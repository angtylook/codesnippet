//Load the http module to create an http server
var http = require('http');
var url = require('url');

function start(route, handle) {

function onRequest(request, response) {
	var pathname = url.parse(request.url).pathname;
	console.log("Request for " + pathname + " received.");

	route(handle, pathname, response);
}

var server = http.createServer(onRequest);

//Listen on port 8000, Ip defaults to 127.0.0.1
server.listen(8000);

//Put a friendly message on the terminal
console.log("Server running at http://127.0.0.1:8000/");
}

exports.start = start;

