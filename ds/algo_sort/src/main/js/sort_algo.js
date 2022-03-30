// GLOBALS
const DATA_LEN = 40;
var data = [];

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function init_data(data, len) {
  for (let i = 0; i < len; i++) data[i] = i + 1;
}

function shuffle(data) {
  for (let i = data.length - 1; i > 0; i--) {
    let p = Math.floor(Math.random() * i);  // p in the range [0,i)
    let temp = data[p];
    data[p] = data[i];
    data[i] = temp;
  }
}

function draw_data(canvas, data) {
  var ctx = canvas.getContext('2d');

  ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.fillStyle = 'lightgray'
	ctx.fillRect(0, 0, canvas.width, canvas.height);

  var colw = canvas.width / data.length;
  var colh = canvas.height / data.length;

  var space = 5;  // white space between columns

  for (let i = 0; i < data.length; i++) {
		// bar lines
		ctx.fillStyle = 'yellow';
    ctx.fillRect(i*colw + space, canvas.height - colh*data[i],
		                  colw - 2*space, colh*data[i]);

		// box point
		ctx.fillStyle = 'blue';
    ctx.fillRect(i * colw, canvas.height - colh * data[i], colw, colh);

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

async function bubble_sort(data) {
  let n = data.length - 1;
  let swap = true;
  while (swap) {
    swap = false;
    for (let i = 0; i < n; i++) {
      if (data[i] > data[i + 1]) {
				swap_values(data, i, i + 1);
				swap = true;
				// render
				update_drawing();
				await sleep(50);
      }
    }
    n--;
  }
}

async function selection_sort(data) {
  let n = data.length - 1;
  while (n > 0) {
    let max_i = 0;
    for (let i = 0; i <= n; i++)
      if (data[i] > data[max_i]) max_i = i;
    if (max_i != n) swap_values(data, n, max_i);
		--n;
		// render
		update_drawing();
		await sleep(250);
  }
}

async function insertion_sort(data) {
  let n = data.length - 1;
	for (let i = 1; i<=n; i++) {
		let val = data[i];	// value to insert
		let p = i - 1;			// insertion point
		while (p>=0 && val<data[p]) {
			data[p+1] = data[p];
			--p;
			// render
			update_drawing();
			await sleep(50);
		}
		data[p+1] = val
	}
	// render
	update_drawing();
	await sleep(50);
}

async function merge_sort(data, ini, end) {
	console.log("entering merge_sort>> ini: " + ini + "; end: " + end);
	if (ini == end) return;

	let mid = (ini + end + 1)/2;

	// splitting
	merge_sort(data, ini, mid-1);
	merge_sort(data, mid, end);

	// merging
	merge(data, ini, mid, end);
}

async function merge(data, ini, mid, end) {
	console.log("entering merge>> ini: " + ini + "; mid: " + mid + "; end: " + end);
	if(data[mid-1] <= data[mid]) return; // already ordered

	var temp_ar = [];
	let li = ini; // start index of left array
	let ri = mid;	// start index of right array
	let ti = 0;		// temp array index

	// copy elements to temp array in order
	while(li <= (mid-1) && ri <= end) {
		if(data[li] < data[ri]) {
			temp_ar[ti] = ar[li];
			li++;
		}
		else {
			temp_ar[ti] = ar[ri];
			ri++;
		}
		ti++;
	}

	// copy remaining elements of left array (if any)
	// right array remaining elements (if any) are sorted in main array
	while(li < mid) {
		temp_ar[ti] = ar[li];
		li++;
		ti++;
	}

	// update main array
	for(let i=0; i<ti; i++)
		ar[ini + i] = temp_ar[i];

	// render
	update_drawing();
	await sleep(50);
}

function btnReset_onclick() {
  init_data(data, DATA_LEN);
  shuffle(data);
  draw_data(canvas, data);
}

function btnSort_onclick() {
  switch (selAlgo.value) {
    case 'bubble':
      bubble_sort(data);
      break;
    case 'selection':
      selection_sort(data);
      break;
    case 'insertion':
      insertion_sort(data);
      break;
    case 'merge':
      merge_sort(data, 0, data.length-1);
      break;
  }
}

var canvas = document.getElementById('canvas')

var btnReset = document.getElementById('btnReset');
btnReset.onclick = btnReset_onclick;

var btnSort = document.getElementById('btnSort');
btnSort.onclick = btnSort_onclick;

var selAlgo = document.getElementById('selAlgo')

btnReset_onclick();

