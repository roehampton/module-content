# Coursework Specification

The coursework is worth 100% of the total module mark. Delivery of the coursework is divided into four three-week sprints. You will also be evaluated for your contribution to the project. The marks for the coursework are divided as follows:

| **Title**             | **Deadline**  | **Marks** |
| --------------------- | ------------- | --------- |
| Sprint 1              | 16th February | 20%       |
| Sprint 2              | 9th March     | 20%       |
| Sprint 3              | 30th March    | 20%       |
| Sprint 4              | 27th April    | 20%       |
| Individual Reflection | 27th April    | 20%       |

In this coursework, you are tasked with creating a data engineering system (data pipeline) for a business's smooth and efficient data delivery.

Although there is some flexibility, your application must be built using the tools and technologies taught in the module.**

You will work on the project as a Scrum team. You were taught about Scrum in Software Engineering, but if you need clarification, ask the teaching team for more information. **You will work as a team.** You must adopt design and project management methods (Agile, Kanban). You will need to be familiar with the tools of a typical software development team (Visual Studio, Git, Docker) and some of the problematic human and technical issues around collaborating on and continuously improving a data delivery system.

**The nature of your data delivery system is open to you to define. Your limitations are in the technology used (based on those taught in the module) and the scale of the application (significant enough to require using the tools taught in the module).**

You need to do the following for your project:

- Identifying the requirements (functional and non-functional)

- Prioritising the requirements (if applicable)

- Task allocation 

- Identifying the scope of your project

- Identifying the stakeholders

- Risk management

## Group Submission

A group must deliver the coursework. The module assesses your ability to work as a team to deliver a product. Therefore, **most of your coursework grade will be based on your team's ability to work together using the methods defined in the module.**

The coursework submission is monitored weekly during stand-up lab meetings and formally via the code-review assessment points. Your final submission is delivered via your GitHub repository.

## Individual Assessment

Individual contributions to the team will be assessed based on attendance at the various meetings and code reviews and via the metrics gathered from tools such as GitHub. Individual contributions can lead to scaling the overall coursework grade if the team has evidence that illustrates a lack of contribution to the team's deliverable.

The coursework must be delivered as part of a team. **If anyone is dismissed from their team, they cannot deliver the coursework and will fail**. Dismissal from a team involves the following process:

- An individual is evidenced as breaching the student team's code of conduct.

- Evidence is presented at the next available meeting with a member of the module delivery team.

- The individual will have the opportunity to evidence mitigating circumstances either to the student team or privately to a member of the module delivery team.

- The module delivery team retains the right to decide whether the dismissal is warranted.

Any dismissed team member has a week to appeal the decision to the module team with suitable evidence provided.

## Code Review Meetings

Each group will undertake four graded code reviews:

1. Week 4 (20% of CW mark)
2. Week 7 (20% of CW mark)
3. Week 10 (20% of CW mark)
4. Week 12 (20% of CW mark)

The meetings will take place during the lab sessions. Each group will be given 15 minutes maximum for the code review. Your group will be allocated a time for the code review. The details of the individual review points are below. These meetings must be attended at the stated time. Guidelines for grading the group:

- Being late for the meeting or not being ready when the meeting starts will result in the grade for that review being capped at 40%.

- Not attending the meeting will mean the code review will be marked at 0%.

- All team members should attend the code review. However, commitments and other considerations will be taken into account. Individual attendance at reviews will be monitored to ensure the team contributes collectively to the project.

- Being ready means that you are ready to present the points for the code review. This means you have a computer with the various tools logged into (e.g., GitHub) and a building version of the application.

## Sprint Deliverables

### Sprint 1 -- Lab of Week 4

This sprint aims to ensure that the team's project workflow is set up. You may choose to meet some of the feature requirements during this review point, but it is not as necessary.

#### Checklist Submission 1

The following must be in place:

- GitHub project for coursework setup.

- Product backlog created.

- Initial tasks are defined as user stories.

- Kanban/project board being used.

- Sprint boards are being used.

- Necessary starting docker files for the project set up and working.

- Correct branches for GitFlow workflow created -- includes *master*, *develop*, and *release* branches.

- The first release was created on GitHub.

- Code of Conduct defined.

The overall quality of these deliverables, as well as overall metrics from GitHub and code quality, will also be evaluated.

### Sprint 2 -- Lab of Week 7

This sprint aims to ensure that the team's project has determined its set of requirements based on the idea and that you have met some of the initial feature requirements of the submission.

### Sprint 3 -- Lab of Week 10

This sprint aims to ensure that the team's project is nearing completion and is suitably on track for delivery. Most of the features should be in place at this point, and the team moving into refinement and quality improvement.

### Sprint 4 -- Lab of Week 12

This is the final submission deadline, and you should have a working system meeting the general requirements you set up at the start of the project.

## Marking Scheme

Each sprint submission will be judged against the following criteria.

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Satisfactory**                                             | **Fail**                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **System design** uses multiple DAGs, and multiple pipeline stages. Each pipeline stage and DAG is clearly defined and has a clear function. | The design is excellent in its definition, with each DAG used clearly defined and each pipeline stage having a specific and independent purpose. | The design is good, although there are some issues with the scope of the DAGs and pipeline stages. | The design is workable, but overall there needs to be more engineering excellence in what has been delivered at this stage. | The DAGs and pipeline stages must be better defined and have a coherent sense of individual purpose. |
| **Functionality** does the system do what it is meant to? Is it error-free?   Does it use appropriate extraction, transform and load stages? Is data properly integrated and cleaned through the pipeline? | Overall the functionality is excellent and works without error. Appropriate pipeline stages manage ETL, integration, and cleaning through the pipeline. | The functionality is good, but there are some errors and/or only partially using the pipeline to undertake the stages of processing data best. | The functionality is OK, and the system works in many instances. However, the pipeline has yet to be used to ensure coherent data processing stages. | The functionality is poor at best, and the system does not always work overall. There are no opportunities used to process the data effectively before delivery. |
| **Portability** uses Docker effectively so the system can work on every platform.  Any final stage of data delivery (e.g., web page) is usable on many platforms. | The system uses Docker effectively to enable efficient system delivery on any platform.  The final deliverable/interface is usable on any platform. | The system uses Docker and generally works well. It could be undertaken more efficiently. The final data deliverable is generally portable. | The use of Docker is OK, but it could be better. The final data deliverable is less usable on all platforms. | Docker usage could be better and might not fully work. The final data deliverable needs to be more present and usable. |
| **Efficiency,** including removing redundant data transfers. | The system has good efficiency overall and does not enable redundant data transfers. | The system has generally good efficiency, although some redundant data transfers may occur. | The efficiency is satisfactory, and redundant data transfers are manageable. | There needs to be more consideration for efficiency, and data is transferred far too often. |
| **Requirements and requirements management.**                | Excellent requirements definition and management, ensuring successful project delivery. | Goo requirements definition and management, ensuring successful project delivery. | Satisfactory requirements definition and management, ensuring a generally successful project delivery. | Poor requirements definition and management, potentially leading to unsuccessful project delivery. |
| **Extra features**. For example, secure data transfer, use of external APIs, real-time and static data used, and novel ways of sourcing data. | An excellent set of extra features is used.                  | A good set of extra features is used.                        | Only one extra feature was used.                             | No additional features were used.                            |

Each team will assess the other individual members of their team. There will also be a peer review from other teams on your final submission.
