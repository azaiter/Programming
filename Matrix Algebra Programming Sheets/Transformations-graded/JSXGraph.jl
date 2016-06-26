module JSXGraph

# (c) 2016 Jan Hlavacek <jhlavace@svsu.edu>
# Feel free to use in any way you want, an attribution will be appreciated.

export JSXObject, JSXThings, createBoard, combine, addPoints, pointsToPolygon, setProperties

typealias JSXObject ASCIIString

type JSXThings
    board:: JSXObject
    things:: Tuple{Vararg{JSXObject}}
end


function createBoard(name::ASCIIString, left::Real, top::Real, right::Real, bottom::Real, width::Integer, height::Integer)
    s = """
<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="jsxgraph.css" />
        <script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/jsxgraph/0.99.3/jsxgraphcore.js"></script>
    </head>
    <body>
    <div id="box_$name" class="jxgbox" style="width:$(width)px; height:$(height)px;"></div>
    <script type="text/javascript">
        var $name = JXG.JSXGraph.initBoard('box_$name', {boundingbox:[$left,$top,$right,$bottom], axis:true});
    </script>
    </body>
</html>
"""
    display("text/html", s)
    return name
end

showThings(t::JSXThings) = "[" * join(["$(t.board)_$thing" for thing in t.things],",") * "]"

function combine(first::JSXThings, second::JSXThings)
    if first.board != second.board
        throw(ErrorException("Cannot combine lists of JSXgraph objects that belong to different boards!"))
    else
        return JSXThings(first.board, tuple(first.things...,second.things...))
    end
end

function addPoints{T<:Number}(board::JSXObject, points::Array{T,2}, prefix::ASCIIString)
    if size(points,1) != 2
        throw(ErrorException("Array describing points must have exactly 2 rows!"))
    end
    s = "<script type=\"text/javascript\">\n"
    for i in 1:size(points,2)
        s *= "var $(board)_$prefix$i = $board.create('point',$(points[:,i]),{'fixed':true});\n"
    end
    s *= "</script>"
    display("text/html",s)
    return JSXThings(board,tuple(["$prefix$i" for i in 1:size(points,2)]...))
end

function pointsToPolygon(points::JSXThings, poly_name::ASCIIString)
    s = """
    <script type="text/javascript">
        var $(points.board)_$poly_name = $(points.board).create('polygon', $(showThings(points)));
    </script>
    """
    display("text/html",s)
    return JSXThings(points.board, (poly_name,))
end

function setProperties(things::JSXThings, properties)
    s = "<script type=\"text/javascript\">\n"
    for thing in things.things
        s *= "$(things.board)_$(thing).setProperty({" * 
              join(["$key:$value" for (key, value) in properties],',') *
              "});\n"
    end
    s *= "</script>"
    display("text/html",s)
end

end
