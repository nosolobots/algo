// GLOBALS
const DATA_LEN = 40;
var data = [];

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function init_data(data, len) {
    for(let i=0; i<len; i++)
        data[i] = i+1;
}

function shuffle(data) {
    for(let i=data.length-1; i>0; i--) {
        let p = Math.floor(Math.random()*i); // p in the range [0,i)
        let temp = data[p];
        data[p] = data[i];
        data[i] = temp;
    }
}

function draw_data(canvas, data) {
    var ctx = canvas.getContext("2d");

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    ctx.fillStyle = "blue";
    
    var colw = canvas.width/data.length;
    var colh = canvas.height/data.length;
    
    var space = 2;    // white space between columns

    for(let i=0; i<data.length; i++) {
        //ctx.fillRect(   i*colw + space, canvas.height - colh*data[i], 
        //              colw - 2*space, colh*data[i]); 
        
        ctx.fillRect(i*colw, canvas.height - colh*data[i], colw, colh);

        //ctx.fillRect(i*colw, canvas.height - colh*data[i], colw, colh*data[i]); 
    }
}

function update_drawing() {
    draw_data(canvas, data);
}

function swap_values(data, i, j) {
    let temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

async function bubble(data) {
    let n = data.length - 1;
    let swap = true;
    while(swap) {
        swap  = false;
        for(let i=0; i<n; i++) {
            if(data[i]>data[i+1]) {
                swap_values(data, i, i+1);
                swap = true;
            }
            update_drawing();
            await sleep(10);             
        }
        n--;
    }
}

function btnReset_onclick() {
    init_data(data, DATA_LEN);
    shuffle(data);    
    draw_data(canvas, data);
}

function btnSort_onclick() {
    bubble(data);
}

var canvas = document.getElementById("canvas")

var btnReset = document.getElementById("btnReset");
btnReset.onclick = btnReset_onclick;

var btnSort = document.getElementById("btnSort");
btnSort.onclick = btnSort_onclick;

btnReset_onclick();

