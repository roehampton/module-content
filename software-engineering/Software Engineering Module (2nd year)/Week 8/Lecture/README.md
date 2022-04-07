# Lecture 8: Monitoring Software

This lecture focuses on monitoring our applications.  It is really an introduction to the ideas, and the recommended reading is a good place to work from if you want to practically build such a system.

## Behavioural Objectives

- [ ] **Define** *information visualisation.*
- [ ] **Describe** *system monitoring.*
- [ ] **Define** the *requirements for a system monitoring framework.*
- [ ] **Define** *application monitoring approaches.*

## Information Visualisation

From [Wikipedia](https://en.wikipedia.org/wiki/Information_visualization):

> Information visualization or information visualisation is the study of (interactive) visual representations of abstract data to reinforce human cognition.

Visualisation is about the graphical representation of data in a manner that helps people understand what the data means.  It is a very large field of research, including organisations such as Google, Adobe, and IBM.  We will not go into the methods and principles of information visualisation here, but it is worth noting that our discussion on monitoring software has roots in this area.

Below is an example visualisation:

<p><a href="https://commons.wikimedia.org/wiki/File:Internet_map_1024.jpg#/media/File:Internet_map_1024.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/Internet_map_1024.jpg/1200px-Internet_map_1024.jpg" alt="Internet map 1024.jpg"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=Barrett_Lyon&amp;action=edit&amp;redlink=1" class="new" title="Barrett Lyon (page does not exist)"> The Opte Project</a> - Originally from the <a href="https://en.wikipedia.org/wiki/Main_Page" class="extiw" title="en:Main Page">English Wikipedia</a>; description page is/was <a href="https://en.wikipedia.org/wiki/en:Image:Internet_map_1024.jpg" class="extiw" title="w:en:Image:Internet map 1024.jpg">here</a>., <a href="https://creativecommons.org/licenses/by/2.5" title="Creative Commons Attribution 2.5">CC BY 2.5</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=1538544">Link</a></p>

This is a (partial) map of the Internet in 2005.  The lines represent two machines being connected, and the colour the length of delay between the machines connected.  The aim is to spot patterns and then investigate further.  This allows **exploration** of data.

### Software Visualisation

*Software Visualisation* is a field of information visualisation research focused on the visual representation of software data.  As we have highlighted, there is a lot of data that can be generated about our code and its runtime environment.  Below is an image that represents the Ndepend Tool's unit test code coverage.

![Code Coverage Treemap](img/code-coverage.png)

Source: https://www.ndepend.com/docs/treemap-visualization-of-code-metrics

The visualisation uses the following techniques:

- the **size** of a square represents the *total lines of code (LoC)* for that method, class, namespace.
- the **colour** of a square represents the *percentage coverage* of unit test: green being good, red being bad.

Straight away we can spot where we might want to write more tests to improve the quality of our code.  The visualisation has presented information and we can see the patterns of interest.

Another visual representation you may be familiar with is from your Git branches.  Below is an example:

![Git Branches](img/git-branches.png)

Source: https://www.tablix.org/~avian/blog/archives/2014/06/vesna_drivers_git_visualization/.

The main use of this view is during development, allowing us to trace history or support our merging work.  Again, we look for patterns to understand our information.

Finally, visualisation has been used to illustrate behaviour.  Below is an example of a quicksort algorithm working:

<p><a href="https://commons.wikimedia.org/wiki/File:Quicksort.gif#/media/File:Quicksort.gif"><img src="https://upload.wikimedia.org/wikipedia/commons/f/fe/Quicksort.gif" alt="Quicksort.gif"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Simpsons_contributor&amp;action=edit&amp;redlink=1" class="new" title="User:Simpsons contributor (page does not exist)">Simpsons contributor</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/3.0" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=14918391">Link</a></p>

This visualisation can be used to help explain how something works, to see how it works, or to check it does work.

### Business Dashboard

Our aim when building monitoring tools for software is to create dashboards.

<p><a href="https://commons.wikimedia.org/wiki/File:3_Dashboards.JPG#/media/File:3_Dashboards.JPG"><img src="https://upload.wikimedia.org/wikipedia/commons/c/c7/3_Dashboards.JPG" alt="3 Dashboards.JPG"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Kate07lyn&amp;action=edit&amp;redlink=1" class="new" title="User:Kate07lyn (page does not exist)">Kate07lyn</a> - Jinfonet Software, <a href="https://creativecommons.org/licenses/by-sa/3.0" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=13309105">Link</a></p>

From [Wikipedia](https://en.wikipedia.org/wiki/Dashboard_(business)):

> Dashboards often provide at-a-glance views of key performance indicators (KPIs) relevant to a particular objective or business process. In the other, "dashboard" has another name for "progress report" or "report."

Dashboards provide easy visuals for us to see important information about the organisation.  We want to see quickly how well we are meeting our targets.  This may include financial information, geographic information, or other performance indicators:

<p><a href="https://commons.wikimedia.org/wiki/File:Infruid%27s_Self-Service_BI_Tool_Dashboard.jpg#/media/File:Infruid%27s_Self-Service_BI_Tool_Dashboard.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/b/b7/Infruid%27s_Self-Service_BI_Tool_Dashboard.jpg" alt="Infruid's Self-Service BI Tool Dashboard.jpg" height="345" width="640"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Growthlakes&amp;action=edit&amp;redlink=1" class="new" title="User:Growthlakes (page does not exist)">Growthlakes</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/4.0" title="Creative Commons Attribution-Share Alike 4.0">CC BY-SA 4.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=60026450">Link</a></p>

## Monitoring Systems

System monitoring is about knowing the state of the technology environment.  We use monitoring to:

- Detect faults.
- Diagnose faults.
- Resolve faults.

Monitoring also provides data to support the business, such as:

- user experience data.
- where to make product and technology investments.

An example monitoring dashboard is below:

<p><a href="https://commons.wikimedia.org/wiki/File:ScalableGridEngineGanglia2.png#/media/File:ScalableGridEngineGanglia2.png"><img src="https://upload.wikimedia.org/wikipedia/commons/5/56/ScalableGridEngineGanglia2.png" alt="Screenshot" height="392" width="640"></a><br>By <a href="//commons.wikimedia.org/wiki/User:Raysonho" title="User:Raysonho">Raysonho @ Open Grid Scheduler / Grid Engine</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.en" title="Creative Commons Zero, Public Domain Dedication">CC0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=27359495">Link</a></p>

Technically, monitoring is the tools and processes to measure and manage IT systems.  However, monitoring goes further than this because we translate the metrics into business value.  This comes from measuring the user experience.  The better the user experience, the more people will use your system.  We also gain data on how people use the system, thus supporting investment and decision making.  It also supports the operations team in delivery quality of service.  Therefore, any monitoring system has two customers:

- the business.
- the IT (operations) team.

Monitoring is important.  It is often considered an add-on, much like security.  **Do not see monitoring as an add-on.**  It is a core function to your work as a software engineer.  You need to know how your software is working.  **You are an engineer - not a cowboy.**  So monitoring should be in your user stories, and in all your software components.

**Not adding monitoring creates operational risk.**  This results in (taken from *The Art of Monitoring*):

- An inability to identify or diagnose faults.
- An inability to measure the operational performance of your application.
- An inability to measure the business performance and success of an application or a component, like tracking sales figures or the value of transactions.

Also, we need to recognise that over-instrumentation is best.  You are more likely to complain about not having enough data rather than too much.

## Monitoring Culture

Applying monitoring in an organisation is again a cultural issue.  *The Art of Monitoring* has defined a three-level organisational maturity model of monitoring.

### Manual Monitoring or None

Monitoring is a manual process that requires a person to initiate.  It may also be the case that no monitoring is done at all.  Generally, monitoring is done via a checklist, simple script, or other non-automated processes.

The aim in manual monitoring is to manage assets and avoid downtime, and thus provides little value on user experience and quality of service.  It will not allow the development and operations teams to justify investments and new projects as there is no data to support it.

### Reactive Monitoring

Reactive monitoring automates most of the processes with some left as manual.  Tooling will have been deployed to perform the monitoring process.  However, the same aims exist - measuring availability and managing assets.  More sophisticated metrics may exist that support customer experience.

The term reactive is used as this form of monitoring is expanded in response to incidents.  The operations team are generally running the system and thus metrics are focused on their needs.

### Proactive Monitoring

Proactive monitoring supports infrastructure and the business.  It is done automatically and generated as part of configuration management.  Metrics focus on application performance and business outcomes rather than just disk and CPU usage.  Quality of service and user experience are key.  Also, the data allows the development and operations team to justify investment.

The operations team will manage monitoring, but everyone sees it as a responsibility.  The development team will build it into new products, and the definition of done will include monitoring.

## A Monitoring Framework

An example of a monitoring framework is below:

![Monitoring Framework](img/monitoring-framework.png)

Source: *The Art of Monitoring.*

In general, we should monitor systems using push-based methods rather than pull-based.  That is, our systems should **emit** data rather than be requested for it.  The data should be emitted to a central collector for management.

An emitter reports that it is available by emitting data.  An emitter is also stateless - it just sends the data to the collector when it is generated.  If a metric is available, an event reporting, or log is spooling then the service is available.  If it stops, then the service is not available.  We then visualise these metrics, events and logs to allow the team to interpret the complex information gathered.

This change to emitting moves the focus from service availability in our monitoring system.  If IT assets are judged as capital and operational expenses then they can be cut.  Availability only provides this view.  Additional monitoring illustrates the value in investing in IT infrastructure and other projects.

Operations teams used to see hosts (servers) as pets.  They fixed and nursed their pets back to life multiple times, fiddling with settings, and investing time in their health.  Our work in Docker and now in cloud infrastructure points to a different view.  Hosts are a herd.  We automatically configure, rebuild, kill, restart and add hosts.  It is easy.  We do not see the single machine any more, but a host environment that we can spin up and shutdown as needed.  This removes a wealth of checks in our system - we just rebuild a host or component if it fails.  It also changes the view of IT assets.

Fault detection systems have traditionally only provided true/false information.  Also, the systems were developed using static ideas:

- You implement the same checks you've used in the past or from the documentation.
- You implement a check in response to an incident..

*The Art of Monitoring* highlights three approaches to monitoring applications:

- Emitting metrics by instrumenting code.
- Generating structured or semantic log events.
- Building health checks and endpoints.

We will not go into any of these in detail, but *The Art of Monitoring* walks through how to build such a system from the ground up.  If you want to build your own monitoring system you should use this book.

### Metrics and Events

*The Art of Monitoring* specifies the following types of data that can be gathered:

- Resource information, like consumption of CPU or memory 
- Performance information, like latency and application throughput 
- Business and user-experience metrics, like volumes or the amounts of transactions or numbers of failed logins 
- Log data from hosts, services, and applications

Generally, these can be divided into the following three categories:

- **Events**: changes and occurrences in our environment.
- **Logs**: a subset of events most useful for fault diagnosis and investigation.
- **Metrics**: most useful to help us understand what's going on in our environment.

Metrics are measures of software and hardware properties.  A metric involves keeping track of a state by making an observation which is a value and a timestamp, with possibly some other properties of interest.  *We are undertaking a scientific approach here.*  We gather the appropriate data to allow us to make hypothesis and judgements on system performance.

Metrics change our view from fault-detection to state, availability and performance of our system.  They provide a dynamic, real-time understanding of the application and allow us to make good decisions about its use and expansion.  Metrics may also provide data to catch faults before they occur.

### Notifications

A monitoring system must provide notifications.  These can be emails (such as Travis does), text messages, or pop-ups.  *The Art of Monitoring* defines the basics of a notification system as:

- Who to tell about a problem.
- How to tell them.
- How often to tell them.
- When to stop telling them, do something else, or escalate to someone else.

A good notification framework should:

- Make notifications actionable, clear, and articulate.
- Add context to notifications.
- Align notifications with the business needs of the service being monitored.

### Approaches to Monitoring

There are two two approaches to monitoring:

- **Blackbox** where you query a service to check properties such as availability.
- **Whitebox** where you emit data from your application.

Blackbox monitoring should be used on services and applications outside your system.  You have little to no control over such systems, and so must gather whatever data you can to ensure the health of your system.

Whitebox monitoring is the approach taken by your own system.  You emit data to the collector, providing as much instrumentation as feasible.  As a software engineer, you are more concerned with whitebox monitoring as you are writing the applications involved.

## Application Monitoring

![Application Monitoring](img/application-monitor.gif)

Source: https://www.splunk.com/en_us/it-operations/application-analytics-and-monitoring.html.

When building application monitoring the first areas to work on are entry and exit points from our system (from *The Art of Monitoring*):

- Measure and log requests and responses.
- Measure and log all calls to external services and APIs.
- Measure and log job scheduling, execution, and other periodic events.
- Measure significant business and functional events.
- Measure methods and functions that read and write from databases and caches.

An endpoint is where we interface with the system (e.g., a URL listening point).  We can test availability, gather performance metrics, etc.  This can be returned in JSON data format that we can then store in our central collector.

There are two types of metrics for applications:

- **Application metrics**: the state and performance of application code.
- **Business metrics**: the value of your application (e.g., sales made).

Application metrics focus on user experience (e.g., response time), throughput (e.g., request volume), and transaction time.  Business metrics often use application metrics.  For example, payment latency increases the cost of processing payments, which is a business cost.

Commonly, a library to support monitoring is used.  An API call allows us to store our values in our central gathering point.  This provides a unified monitoring interface.  If we cannot insert code directly (e.g., external systems, blackbox systems, legacy systems), we put the monitoring as close to the measuring point as we can.

### Metric Types and Visual Approaches

Finally, we can consider the types of metrics we can gather and how to visualise them.  In simple terms, we have the following metric types:

- **Gauges** show a number that will change over time (e.g., CPU usage).  We want to see the metric at a given point in time.
- **Counters** increase over time, such as uptime and sales.  Useful for mapping rates of change.
- **Timers** are used to determine how long something took, for example a request.
- **Summaries** combine metrics into a more useful statistic.  For example, means, medians, percentages, etc.

A gauge can be a simple number or a visual metaphor such as a real gauge:

<p><a href="https://commons.wikimedia.org/wiki/File:Psidial.jpg#/media/File:Psidial.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/e/e4/Psidial.jpg" alt="Psidial.jpg" height="480" width="480"></a><br>By <a rel="nofollow" class="external text" href="https://www.flickr.com/photos/54613528@N00">leapingllamas</a> - <a rel="nofollow" class="external text" href="https://www.flickr.com/photos/54613528@N00/11897019">Flickr</a>, <a href="https://creativecommons.org/licenses/by/2.0" title="Creative Commons Attribution 2.0">CC BY 2.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=794301">Link</a></p>

Other metaphors normally include bar/column charts (for discrete data) and line charts (for continuous data).

## Summary

In this lecture we have examined application monitoring at a very high level.  In particular, we have:

- Defined information visualisation as the graphical representation of data in a manner that helps people understand what the data means.
- Described system monitoring, looking at what to monitor and the culture required.
- Defined the requirements for a system monitoring framework, including emitters and notifications.
-Defined application monitoring approaches, looking at what to monitor and how to present this.

## Recommended Reading

*The Art of Monitoring* by James Turnbull covers both the principles of monitoring and how to build a monitoring system.  If you want to build a monitoring feedback this is a good starting point.

![The Art of Monitoring](img/monitoring-book.jpg)