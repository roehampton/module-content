# Computer Systems Coursework 2 -- System Performance

Part 2 of the coursework is worth 60% of the total coursework mark. The submission deadline is **Friday 18th December online via Moodle by 23.59.**

Part 2 of the coursework focuses on system performance. This covers the module learning outcomes:

- *Use software tools to profile and measure program performance.*
- *Evaluate performance of simple sequential and parallel versions of a program with different problem sizes, and be able to describe the speed-ups achieved.*

The aim of this coursework is to produce a report based on the below scenario.

## Scenario

Your company just won a contract with the English Premier League (EPL) to encode and deliver their digital archive. Your company is willing to invest in new computing resource to complete the work. They are looking for the best return of investment, that is the cheapest method that meets the specifications made by the EPL.

The table below defines five different systems from different manufacturers that are available, including:

- The number of cores available on each system.
- The time taken, in hours, to encode 1 hour of video content at different resolutions:
  - 720p
  - 1080p
  - 2160p
- The cost to buy the system.
- The running cost of the system per hour.

| System | Cores | 720p hour encoding | 1080p hour encoding | 2160p hour encoding | Initial Cost | Cost Per Hour |
| ------ | ----- | ------------------ | ------------------- | ------------------- | ------------ | ------------- |
| 1      | 1     | 8 hours            | 16 hours            | 32 hours            | £3000        | £0.30         |
| 2      | 2     | 6 hours            | 12 hours            | 24 hours            | £5000        | £0.60         |
| 3      | 4     | 3 hours            | 6 hours             | 12 hours            | £10000       | £1.00         |
| 4      | 8     | 1 hour             | 2 hours             | 4 hours             | £20000       | £1.50         |
| 5      | 16    | 0.25 hours         | 0.50 hours          | 1 hour              | £0           | £5.00         |

The EPL also want to ensure their fans have the best experience when watching video online. They have asked you to test the following browsers and determine which one is best:

- Microsoft Edge
- Google Chrome
- Mozilla Firefox

To test the performance, they have provided a test video (https://youtu.be/LXb3EKWsInQ). They require testing of all resolutions (720p, 1080p, 2160p).

The EPL has 100,000 hours of content to encode. They require 50% of the content to be available in twelve weeks, and the following 75% in 24 weeks, and the full 100% in one year.

As the head of the system engineering department, you have been given the responsibility to draft a report on the following:

- Relative performance of the different systems as measured in speedup in comparison to System 1 for the different workloads.
- The cost of using each system to encode video for each milestone and the overall cost. The EPL require encoding in all resolutions defined. You can buy as many instances of a system as required to meet the contract requirements.
- A recommendation on which system provider to purchase systems from based on cost to deliver the contract.
- An analysis of streaming the test video in full-screen in each resolution using Window's Performance Monitor.
- A recommendation on which browser the EPL should recommend to their fans.

## Submission Requirements

Your document must be uploaded in PDF and have the following document properties:

- Paper size - A4.
- Font - Arial, 11pt for all main body text (including tables). Headings Arial, 11pt minimum.
- Margins - 2cm all sides.
- Single line spacing.
- Single column.
- 4 pages maximum -- **Reports longer than 4 pages will be capped.**

## Marking Scheme

The following rubric will be used to assess your work.

| Criteria                                                     | Excellent                                                    | Good                                                         | Developing                                                   | Not Attempted                                                |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Speedup metrics** correctness of the measurements and their presentation. | All speedup measures are correctly calculated and well presented in appropriate charts (e.g., bar charts). | Most speedup measures correctly calculated and generally well presented in appropriate charts. | Some speedup measures correctly calculated and some chart presentation issues. | Speedup measurements insufficient and/or incorrect. Charts used are not appropriate. |
| **Costings** correctness of the costing and their presentation. | Correct costings calculated for all instances and milestones and well presented in a table. | Most costings calculated for instances and milestones and presented in a table. | Some costings calculated or costings calculated are not presented well. | Costings provided insufficient and/or incorrect. Not well presented. |
| **Browser analysis** correctness of the measurements and their presentation. | Browser analysis undertaken for all browsers in all scenarios with suitable presentation of data. | Most browser analysis undertaken with suitable presentation of data. | Some browser analysis undertaken but results are not presented well. | Browser analysis results insufficient and/or incorrect. Not well presented. |
| **Presentation** how well organised is the report.           | Good organisation, points are logically ordered, report order flows together. | Organised, although some points are somewhat jumpy. General flow of report works. | Some organisation points jump around. Flow is unclear.       | Poorly organised. No logical progression. Overall flow is vague. |
| **Discussion** overall level of discussion in the report.    | Excellent overall level of discussion provided.              | Good discussion level provided although unclear or inconsistent in a couple of places. | Discussion is good but lacks clarity and consistency in places. | Discussion is poor and does not provide clarity to the report. |
| **Format** ability to meet the formatting standard defined.  | Report is in the correct format.                             | Report is mostly in the correct format.                      | Report has a few formatting issues.                          | Report has many formatting issues or does not meet the guidelines specified. |

## Academic Misconduct

All submissions will be processed through TurnitIn. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx. Our guiding principle is:

> Academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly.
