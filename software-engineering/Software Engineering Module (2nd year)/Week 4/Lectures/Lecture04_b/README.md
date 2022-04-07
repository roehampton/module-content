# Lecture 04b: Introduction to DevOps



The combination of agile, lean, and modern build tools has lead to the DevOps (**Development** and **Operations**) culture.  Here, developers (e.g. software engineers) work closely with the operators (e.g. system deployment) to automate and monitor the entire software development lifecycle.  It can be seen as the intersection of three core software delivery ideas:

<p><a href="https://commons.wikimedia.org/wiki/File:Devops.svg#/media/File:Devops.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Devops.svg/1200px-Devops.svg.png" alt="Devops.svg"></a><br>By <a href="//commons.wikimedia.org/wiki/File:Devops.png" title="File:Devops.png">Devops.png</a>: <a href="//commons.wikimedia.org/w/index.php?title=User:Rajiv.Pant&amp;action=edit&amp;redlink=1" class="new" title="User:Rajiv.Pant (page does not exist)">Rajiv.Pant</a>
derivative work: <a href="//commons.wikimedia.org/wiki/User:Wylve" title="User:Wylve">Wylve</a> - This file was derived from:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Devops.png" title="File:Devops.png">Devops.png</a>:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Devops.png" class="image"></a>, <a href="https://creativecommons.org/licenses/by/3.0" title="Creative Commons Attribution 3.0">CC BY 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=20202905">Link</a></p>

1. **Development** is typically seen as the software engineer's role.  The focus of this module is software engineering so we will look at DevOps ideas through this lens.
2. **Operations** is the management of systems where software runs.  Software does not exist on a developers machine, but integrates with existing systems and on platforms managed by the business.
3. **Quality Assurance** is where testing typically resides, although software quality is a bigger area than just testing.  Ensuring *production* quality software is the key for a DevOps team.

DevOps is not just about tools and techniques - *DevOps is also a cultural idea in an organisation*.  It requires parts of the organisation traditionally seen as adversarial to work together in a trusting environment.

DevOps has five goals (taken from [Wikipedia](https://en.wikipedia.org/wiki/DevOps)):

1. Improved deployment frequency.
2. Faster time to market.
3. Lower failure rate of new releases.
4. Shortened lead time between fixes.
5. Faster mean time to recovery.

Notice that all these ideas are about speed and effectiveness.  **Flow of work** is a key idea in DevOps.  Ideas such as number of deployments per day are key concepts in DevOps that you should explore.

- [ ] Watch the video below about Flickr's adoption of DevOps.
- [ ] Reflect on what it would take to do multiple software deployments a day, and how your own software development practice should change to reflect this.
- [ ] Do some research (e.g. a web search) on other deployment frequency stories.  Google and Amazon are particularly frequent.

[![10+ Deploys Per Day](https://img.youtube.com/vi/LdOe18KhtT4/0.jpg)](https://www.youtube.com/watch?v=LdOe18KhtT4)

### DevOps-toolchain

A key concept in DevOps is the creation of a *DevOps-toolchain*: a series of tools and techniques that support the goals of DevOps.  There are different interpretations, but the image below illustrates one set of stages:

<p><a href="https://commons.wikimedia.org/wiki/File:Devops-toolchain.svg#/media/File:Devops-toolchain.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/05/Devops-toolchain.svg/1200px-Devops-toolchain.svg.png" alt="Devops-toolchain.svg"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Kharnagy&amp;action=edit&amp;redlink=1" class="new" title="User:Kharnagy (page does not exist)">Kharnagy</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/4.0" title="Creative Commons Attribution-Share Alike 4.0">CC BY-SA 4.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=51215412">Link</a></p>

There are seven stages here:

1. **Plan** the work to be done and its requirements from both the development and operation side.  We will do very minimal planning in the module only looking at **use cases** and **user stories** for software requirements.  We will use **Kanban**-style boards via **GitHub** to support planning.
2. **Create** the software - that is design and code the application with consideration of quality and performance requirements.  This is more the realm of software development covered in other modules, but we do add **UML** and **model-driven development** into the mix of techniques available to you.  Extensive use of version control with **Git** is also used to ensure different parts of the development are managed.
3. **Verify** is the testing of the software, including that the code is of production quality.  **Unit testing** vaguely falls into this category, although is arguably also a *create* task due to its granularity.  We do look at **configuration testing** and **continuous integration** to an extent via **Travis CI** and **Docker**.
4. **Package** the software ready for release/deployment.  We do a *very* light approach to packaging via **Maven** and the creation of a deployable JAR file.
5. **Release** the software into production in the target environment.  We will deploy our software to **Amazon Web Services** as a simulation of this idea, but releasing software to a production environment is not about *greenfield* (new software) environments.
6. **Configure** the IT infrastructure that the software runs in.  This falls under the operations side of DevOps, and we will only touch on basic concepts such as **Docker** and configuration in **Amazon Web Services**.
7. **Monitor** the running software on the target infrastructure.  Monitoring our system allows us to *plan* the next work.  We will do little on monitoring beyond information returned by **Amazon Web Services** although we will consider **bug-tracking** and **issue-tracking** concepts which can be utilised to monitor software.
