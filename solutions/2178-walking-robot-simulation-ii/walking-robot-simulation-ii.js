var Robot = function (width, height) {
    this.moved = false;
    this.idx = 0;
    this.pos = [];
    this.dir = [];
    this.toDir = {
        0: "East",
        1: "North",
        2: "West",
        3: "South",
    };

    for (let i = 0; i < width; ++i) {
        this.pos.push([i, 0]);
        this.dir.push(0);
    }
    for (let i = 1; i < height; ++i) {
        this.pos.push([width - 1, i]);
        this.dir.push(1);
    }
    for (let i = width - 2; i >= 0; --i) {
        this.pos.push([i, height - 1]);
        this.dir.push(2);
    }
    for (let i = height - 2; i > 0; --i) {
        this.pos.push([0, i]);
        this.dir.push(3);
    }
    this.dir[0] = 3;
};

Robot.prototype.step = function (num) {
    this.moved = true;
    this.idx = (this.idx + num) % this.pos.length;
};

Robot.prototype.getPos = function () {
    return this.pos[this.idx];
};

Robot.prototype.getDir = function () {
    if (!this.moved) {
        return "East";
    }
    return this.toDir[this.dir[this.idx]];
};