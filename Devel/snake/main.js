let canvas = document.getElementById("canvas");
let ctx = canvas.getContext("2d");

const WIDTH = canvas.width;
const HEIGHT = canvas.height;
const BLOCK_SIZE = 10;

let score = 0;

function drawBorder () {
    ctx.fillStyle = "Gray";
    ctx.fillRect(0, 0, WIDTH, BLOCK_SIZE);
    ctx.fillRect(0, HEIGHT - BLOCK_SIZE, WIDTH, BLOCK_SIZE);
    ctx.fillRect(0, 0, BLOCK_SIZE, HEIGHT);
    ctx.fillRect(WIDTH - BLOCK_SIZE, 0, BLOCK_SIZE, HEIGHT);
}

function drawScore () {
    ctx.font = "20px Courier";
    ctx.fillStyle = "Black";
    ctx.textAlign = "left";
    ctx.textBaseline = "top";
    ctx.fillText("Score: " + score, BLOCK_SIZE, BLOCK_SIZE);
}

function gameOver () {
    clearInterval(intervalID);
    ctx.font = "60px Courier";
    ctx.fillStyle = "Black";
    ctx.textAlign = "center";
    ctx.textBaseline = "middle";
    ctx.fillText("Game Over", WIDTH / 2, HEIGHT / 2);
}

class Block {
    constructor (col, row) {
        this.col = col;
        this.row = row;
    }
    drawSquare (color) {
        let x = this.col * BLOCK_SIZE;
        let y = this.row * BLOCK_SIZE;
        ctx.fillStyle = color;
        ctx.fillRect(x, y, BLOCK_SIZE, BLOCK_SIZE);
    }
    drawCircle (color) {
        let cx = this.col * BLOCK_SIZE + BLOCK_SIZE / 2;
        let cy = this.row * BLOCK_SIZE + BLOCK_SIZE / 2;
        ctx.fillStyle = color;
        ctx.beginPath();
        ctx.arc(cx, cy, BLOCK_SIZE / 2, 0, Math.PI * 2, 0);
        ctx.fill();
    }
    equal (otherBlock) {
        return (this.row === otherBlock.row) && (this.col === otherBlock.col);
    }
}

class Snake {
    constructor () {
        this.segments = [
            new Block(7, 5),
            new Block(6, 5),
            new Block(5, 5)
        ];

        // right down left up
        this.direction = 0;
        this.nextDirection = 0;
    }
    draw () {
        for (let i = 0; i < this.segments.length; i++) {
            this.segments[i].drawSquare("Blue");
        }
    }
    move () {
        let head = this.segments[0];
        let newHead;

        this.direction = this.nextDirection;
        switch (this.direction) {
            case 0:
                newHead = new Block(head.col + 1, head.row);
                break;
            case 1:
                newHead = new Block(head.col, head.row + 1);
                break;
            case 2:
                newHead = new Block(head.col - 1, head.row);
                break;
            case 3:
                newHead = new Block(head.col, head.row - 1);
                break;
        }

        if (this.checkCollision(newHead)) {
            gameOver();
            return;
        }
        this.segments.unshift(newHead);

        if (newHead.equal(apple.position)) {
            score++;
            apple.move();
        } else {
            this.segments.pop();
        }
    }
    checkCollision (head) {
        let leftCollision = (head.col === 0);
        let rightCollision = (head.col === WIDTH / BLOCK_SIZE - 1);
        let upCollision = (head.row === 0);
        let downCollision = (head.row === HEIGHT / BLOCK_SIZE - 1);
        let wallCollision = leftCollision || rightCollision || upCollision || downCollision;
        let selfCollision = false;
        for (let i = 0; i < this.segments.length; i++) {
            selfCollision = selfCollision || head.equal(this.segments[i]);
        }
        return wallCollision || selfCollision;
    }
    setDirection (direction) {
        if (this.direction - direction === 2 || this.direction - direction === -2) {
            return;
        }
        this.nextDirection = direction;
    }
}

class Apple {
    constructor () {
        this.position = new Block(10, 10);
    }
    draw () {
        this.position.drawCircle("LimeGreen");
    }
    move () {
        let randomCol = Math.floor(Math.random() * (WIDTH / BLOCK_SIZE - 2)) + 1;
        let randomRow = Math.floor(Math.random() * (HEIGHT / BLOCK_SIZE - 2)) + 1;
        this.position = new Block(randomCol, randomRow);
    }
}

let snake = new Snake();
let apple = new Apple();

function KeyDownEvent (event) {
    let directions = {
        37: 2,
        38: 3,
        39: 0,
        40: 1
    };
    let newDirection = directions[event.keyCode];
    if (newDirection !== undefined) {
        snake.setDirection(newDirection);
    }
}

$("body").keydown(KeyDownEvent);

let intervalID = setInterval(mainloop, 100);

function mainloop () {
    ctx.clearRect(0, 0, WIDTH, HEIGHT);
    drawScore();
    snake.move();
    snake.draw();
    apple.draw();
    drawBorder();
}
