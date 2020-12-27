// Import the node-static library
const static = require("node-static");
// Import the http server library
const http = require("http");

// This creates a static file server for on the directory __dirname
// __dirname is the directory the Node application is working in.
// Similar to cwd (Current Working Directory)
var file = new(static.Server)(__dirname);

// The hostname and port the server will listen on.
var hostname = "127.0.0.1";
var port = 3000;

// Create the HTTP server with the function used to service requests.
const server = http.createServer(function(req, res) {
    if (req.url == "/roehampton") {
        res.statusCode = 302;
        res.setHeader("Location", "https://www.roehampton.ac.uk");
        res.end();
    }
    else {
        // Delegate request to the static file server.
        file.serve(req, res);
    }
});

// Start the server.
server.listen(port, hostname, function() {
    console.log(`Server running at http://${hostname}:${port}/`);
});