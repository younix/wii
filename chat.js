var http_in = new XMLHttpRequest();
var http_out = new XMLHttpRequest();
var offset = 0;

function out_event() {
	if (http_out.readyState == 4) {
		if (http_out.status != 500) {
			var len = parseInt(http_out.getResponseHeader(
			    "Content-Length"));

			offset += isNaN(len) ? 0 : len;
			out_area = document.getElementById("out");
			out_area.value += http_out.responseText;
			out_area.scrollTop = out_area.scrollHeight;
		}

		get_output();
	}
}

function get_output() {
	http_out.onreadystatechange = out_event;
	http_out.open("GET", "/cgi/out.cgi", true);
	range = "bytes=" + offset.toString() + "-";
	http_out.setRequestHeader("Range", range);
	http_out.send();
}

function submit_input() {
	var msg = document.getElementById("in").value + '\n';
	document.getElementById("in").value = "";
	http_in.open("POST", "/cgi/in.cgi", true);
	http_in.send(msg);
}

function key(e) {
	if (e.keyCode == 13)
		submit_input();
}
