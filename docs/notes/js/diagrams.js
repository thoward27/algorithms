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

class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
}
class Node {
    constructor(data, prev = undefined, next = null) {
        this.data = data;
        this.prev = prev;
        this.next = next;
        this.widthData = 70;
        this.widthPoint = 30;
        this.height = 75;
        this.start = [];
    }
    get width() {
        return this.widthData + (this.prev !== undefined) * this.widthPoint + (this.next !== undefined) * this.widthPoint;
    }
    get stop() {
        return [this.start[0] + this.width, this.start[1]];
    }
    drawPointers(ctx) {
        var start = this.start[0];
        if (this.prev !== undefined) {
            // Draw the arrow.
            var x = start + this.widthPoint / 2;
            var y = this.start[1] + 3 * this.height / 4;
            if (this.prev === null) {
                ctx.moveTo(x, y);
                x -= 40;
                ctx.lineTo(x, y);
                ctx.stroke();
                drawAngledArrow(ctx, [x, y], [x, this.start[1] + this.height + 25]);

            } else if (this.prev > x) { // prev points forwards
                ctx.moveTo(x, y);
                x -= 40;
                ctx.lineTo(x, y);
                y += 50;
                ctx.lineTo(x, y);
                x = this.prev + 40;
                ctx.lineTo(x, y);
                y -= 50;
                ctx.lineTo(x, y);
                ctx.stroke();
                drawAngledArrow(ctx, [x, y], [this.prev, y]);

            } else {
                // drawAngledArrow(ctx, [x, y], [this.prev, y])
            }

            // Update starting position.
            start = start + this.widthPoint;
        }

        start = start + this.widthData;

        // Draw the next pointer.
        if (this.next !== undefined) {
            // Draw the next pointer.
            var x = start + this.widthPoint / 2;
            var y = this.start[1] + this.height / 4;
            if (this.next === null) {
                ctx.moveTo(x, y);
                x += 40;
                ctx.lineTo(x, y);
                ctx.stroke();
                drawAngledArrow(ctx, [x, y], [x, this.start[1] + this.height + 25]);
            } else if (this.next < x) {
                ctx.moveTo(x, y);
                x += 40;
                ctx.lineTo(x, y);
                y -= 50;
                ctx.lineTo(x, y);
                x = this.next - 40;
                ctx.lineTo(x, y);
                y += 50;
                ctx.lineTo(x, y);
                ctx.stroke();
                drawAngledArrow(ctx, [x, y], [this.next, y]);
            } else {
                drawAngledArrow(ctx, [x, y], [this.next, y]);
            }
        }
    }
    drawNode(ctx, start) {
        this.start = start;
        var x = start[0];
        if (this.prev !== undefined) {
            // Draw the box for the pointer.
            ctx.strokeRect(x, this.start[1], this.widthPoint, this.height);
            x += this.widthPoint;
        }

        // Draw data bin.
        ctx.strokeRect(x, start[1], this.widthData, this.height);
        x += this.widthData;

        // Draw the next pointer.
        if (this.next !== undefined) {
            // Draw the box for the next pointer.
            ctx.strokeRect(x, start[1], this.widthPoint, this.height);
        }
    }
}
class LinkedList {
    constructor() {
        this.list = [];
    }
    append(data) {
        this.list.push(new Node(data));
    }
    draw(ctx, double, circular) {
        const start = new Point(100, 100);

        this.list.forEach(function (node, index) {
            if (double) {
                node.prev = null;
            }
            node.drawNode(ctx, [start.x + index * (node.width + 60), start.y]);
        });

        this.list.forEach(function (node, index) {
            // Configure next and prev
            if (double) {
                var prev = this.list[index - 1];
                node.prev = !!prev ? prev.stop[0] : null;
            }
            var next = this.list[index + 1];
            node.next = !!next ? next.start[0] : null;
            node.drawPointers(ctx);
        }, this);
    }
}