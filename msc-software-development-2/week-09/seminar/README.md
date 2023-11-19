# Software Development 2 Seminar 9 – Team session

Getting ready for sprint 3 - Technical setup checklist


Your goal is to have a consistent but independent development environment for every member of the team.

## CHECKLIST

1. __Git repo setup__ - new project created from scaffolsing files and pushed by a designated person to your shared repo
2. __Get repo shared__ - above repo can be cloned and new work can be pushed by all members of the team
3. __Database__ - created by one person, then dumped to a text file and shared on onedrive.
4. __Databaes shared__ database is accessed and imported locally by all of the team (see https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=76bcef0a-f7b4-45f3-8dbf-aded010e8ea3)
5. __Wireframes for Sprint 3__ - agreed
6. __Allocation of user stories for Sprint 3__ - work allocated to the team members and task board updated


## Details



### Git repo

ONE person in your group should establish the new repository with a NEW set of the scaffolding files from [the docker receipes](https://github.com/lisahas/docker-recipes/tree/master/mysql-phpmyadmin-node).  Use the Readme.md in that directory for a quickstart guide to amending these files for a new project.  Once you have followed those steps, the team member given this task needs to push the scaffolding files up to your PROJECT repostitory. Use this guide: [Adding an existing project to GitHub using the command line](https://docs.github.com/en/get-started/importing-your-projects-to-github/importing-source-code-to-github/adding-an-existing-project-to-github-using-the-command-line)

Each member of the team should now be able to pull these files. They should then add their own .env file (you can share this via oneDrive - you shouldn't share it in git because it contains passwords).  Each team member should then be able to run 

```
docker-compose up
```

and run the project on their local computers.

---

##### HINT

You will now have two different projects (one for the lab, one for your team project) running on your computer that have the same docker-compose configuration.  They run in different directories.  This is fine.  You just need to make sure that, when you start your containers, there are no containers already running for your other project.  in case you can't run your containers and get an error that a port is in use, use the following command:

```
docker ps
```

You will most likely find that you have containers already running; you can stop them by getting the container name or hash and running:

```
docker-stop <hash>
```

Once all conflicting containers have stopped, you will probably find you can build your development environment with docker-compose up as ususal.


---

### Database

You should never share a database via Git or Docker containers as it is likely to contain personal data.

To share a database:

1. ONE member of the team should create the database structure and, if needed, prefill it with test data.
2. That person should create a 'dump' file of the data.  This is easily done via phpMyadmin (export tab, choose SQL). the file suffix will be .sql, but its basically just a text file with a lot of queries!
3. Once the file is downloaded to that team members's local computer, they should upload it to a secure file sharing platform - the University OneDrive is fine for this purpose.
4. They should then share it with team members via the 'share' feature in OneDrive.
5. The other team members can download the .sql file and import to their own local database via phpmyadmin.

VIDEO: 
[https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=76bcef0a-f7b4-45f3-8dbf-aded010e8ea3](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=76bcef0a-f7b4-45f3-8dbf-aded010e8ea3)


## Additional

Note the following references for pug templates:

Official documentation: https://pugjs.org/api/getting-started.html

Cheatsheet: https://devhints.io/pug

Free ebook: https://riptutorial.com/Download/pug.pdf

Tutorial: https://www.sitepoint.com/a-beginners-guide-to-pug/


__Note the following additional lab sheet for building an options list, adding bootstrap, adding images and stylesheets:__

[Code extras](../../code-extras.html)
