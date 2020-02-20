const DATA_LEN = 20;

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
   
    var colw = canvas.width/data.length;
    var colh = canvas.height/data.length;

    console.log("colw: " + colw);
    console.log("colh: " + colw);

    var space = 2;    // white space between columns

    for(let i=0; i<data.length; i++) {
        ctx.fillRect(   i*colw + space, canvas.height - colh*data[i], 
                        colw - 2*space, colh*data[i]);
    }
}

var data = [];
init_data(data, DATA_LEN);
shuffle(data);
draw_data(document.getElementById("canvas"), data);
