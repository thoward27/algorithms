function drawArrow(ctx, start, stop) {
    ctx.beginPath();

    // Draw horizontal line.
    ctx.moveTo(start[0], start[1]);
    ctx.lineTo(stop[0], start[1]);

    // Draw any vertical segments needed.
    if (start[1] != stop[1]) {
        ctx.lineTo()
    }

    // Draw the arrow head
    ctx.lineTo(stop[0] - 15, stop[1] - 10);
    ctx.moveTo(stop[0], stop[1])
    ctx.lineTo(stop[0] - 15, stop[1] + 10);

    ctx.stroke();
    ctx.closePath();
}

function drawAngledArrow(ctx, from, to) {
    //variables to be used when creating the arrow
    var headlen = 10;

    var angle = Math.atan2(to[1] - from[1], to[0] - from[0]);

    //starting path of the arrow from the start square to the end square and drawing the stroke
    ctx.beginPath();
    ctx.moveTo(from[0], from[1]);
    ctx.lineTo(to[0], to[1]);
    ctx.stroke();

    //starting a new path from the head of the arrow to one of the sides of the point
    ctx.beginPath();
    ctx.moveTo(to[0], to[1]);
    ctx.lineTo(to[0] - headlen * Math.cos(angle - Math.PI / 7), to[1] - headlen * Math.sin(angle - Math.PI / 7));

    //path from the side point of the arrow, to the other side point
    ctx.lineTo(to[0] - headlen * Math.cos(angle + Math.PI / 7), to[1] - headlen * Math.sin(angle + Math.PI / 7));

    //path from the side point back to the tip of the arrow, and then again to the opposite side point
    ctx.lineTo(to[0], to[1]);
    ctx.lineTo(to[0] - headlen * Math.cos(angle - Math.PI / 7), to[1] - headlen * Math.sin(angle - Math.PI / 7));

    //draws the paths created above
    ctx.stroke();
    ctx.closePath();
}

function drawNode(ctx, start, prev = undefined, next = undefined) {
    dataWidth = 65;
    pointerWidth = 30;
    height = 75;

    // Draw the previous pointer.
    if (prev !== undefined) {
        // Draw the box for the pointer.
        ctx.strokeRect(start[0], start[1], pointerWidth, height);

        // Draw the arrow.
        var x = start[0] + pointerWidth / 2;
        var y = start[1] + 3 * height / 4;
        if (prev === null) {
            ctx.moveTo(x, y);
            x -= 40;
            ctx.lineTo(x, y);
            ctx.stroke();
            drawAngledArrow(ctx, [x, y], [x, start[1] + height + 25]);

        } else if (prev > x) { // prev points forwards
            ctx.moveTo(x, y);
            x -= 40;
            ctx.lineTo(x, y);
            y += 50;
            ctx.lineTo(x, y);
            x = prev + 40;
            ctx.lineTo(x, y);
            y -= 50;
            ctx.lineTo(x, y);
            ctx.stroke();
            drawAngledArrow(ctx, [x, y], [prev, y]);

        } else {
            drawAngledArrow(ctx, [x, y], [prev, y])
        }

        // Update starting position.
        start[0] = start[0] + pointerWidth;
    }

    // Draw data bin.
    ctx.strokeRect(start[0], start[1], dataWidth, height);
    start[0] = start[0] + dataWidth;

    // Draw the next pointer.
    if (next !== undefined) {
        // Draw the box for the next pointer.
        ctx.strokeRect(start[0], start[1], pointerWidth, height);

        // Draw the next pointer.
        var x = start[0] + pointerWidth / 2;
        var y = start[1] + height / 4;
        if (next === null) {
            ctx.moveTo(x, y);
            x += 40;
            ctx.lineTo(x, y);
            ctx.stroke();
            drawAngledArrow(ctx, [x, y], [x, start[1] + height + 25]);
        } else if (next < x) {
            ctx.moveTo(x, y);
            x += 40;
            ctx.lineTo(x, y);
            y -= 50;
            ctx.lineTo(x, y);
            x = next - 40;
            ctx.lineTo(x, y);
            y += 50;
            ctx.lineTo(x, y);
            ctx.stroke();
            drawAngledArrow(ctx, [x, y], [next, y]);
        } else {
            drawAngledArrow(ctx, [x, y], [next, y])
        }

        // Update starting position
        start[0] = start[0] + pointerWidth;
    }
    return start;
}