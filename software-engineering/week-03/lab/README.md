# The simplest Dockerfile!!

You will create a Dockerfile for a simple webserver.  If you create it in the same directory as an HTML file called index.html, you will be able to access the file via your browser.

## Installing Docker (if you are using your own computer - the uni lab computers already run docker)

#### On Windows

You need to ensure the wsl (Windows subsystem for Linux) is enabled and that you have installed the 'kernal update package'. 

Docker documentation is here  [installing Docker on Windows] (https://docs.docker.com/desktop/windows/wsl/)

In summary the steps are:

   * Enable WSL 2 on Windows: You should be able to do this via powershell with the command
   
```
wsl --install
```

   * Check that wsl is installed and the version is 2
```
  wsl --list –verbose
```

if you get an error then wsl 1 is installed and you should switch to wsl 2 iwth the command

```
wsl --set-default-version 2
```


  * Downloaded and installed the [Linux kernel update package] (https://docs.microsoft.com/windows/wsl/wsl2-kernel).

__Restart your computer when you have followed these steps__

When you install Docker Desktop, ensure that 'Use WSL 2 based engine' is selected.


#### On Mac

You should simply be able to install docker from the Docker.dmg file in the normal way: https://docs.docker.com/desktop/install/mac-install/
Make sure you also have node.js installed


#### On Linux

https://docs.docker.com/desktop/install/linux-install/

## Test your installation

### Run the 'hello-world' docker image.
This may be available via the docker desktop interface -> images -> remote repositories   
Then use the search box.

OR simply open a terminal via Visual Studio Code and type

```
docker run hello-world
```

You should see the image being pulled and some output.  You should NOT have to be signed in to Docker hub.

## Create and run your first application image

1. Create and open an empty, fresh directory on your computer in vs code.
2. Add an index.html file with some basic HTML code
3. Create a new file called Dockerfile.  Its contents should be:

```
FROM nginx:alpine
COPY . /usr/share/nginx/html
```
4. Create an image of this directory

```
docker build -t html-server-image .
```
(Notice the dot at the end)

5. Now run your image

```
docker run -d -p 8080:80 html-server-image
```

6. View your containerised web application at:

```
localhost:8080
```

NOTES: 
You will need to stop the container, rebuild it and run it each time you make a change
If you get a 'port already allocated' error, stop the running container then your run command should work

