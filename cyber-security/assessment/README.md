# Cybersecurity Assessment

This assessment is worth 60% of the total module mark. It comprises of three separate reports, each worth 20% of the total module mark. Details of each report submission and the deadlines are provided below.

All three reports are based on the following scenario.

## Scenario

The University of Roehampton runs a number of systems to support the work of both staff and students. You have been asked to evaluate potential security threats to the university. The following key systems have been identified:

- Student Records System -- it contains information about all current students as well as students who have graduated in the past five years. This system is maintained on a database managed in the cloud.
- Human Resources (HR) System -- it contains information on all current employees at the university and anyone who has been employee in the past five years. The HR System also maintains information on anyone who has applied for a job in the last six months. This system is maintained by an external supplier.
- User Authentication System -- it contains information on users of the university IT systems. It gathers information from the Student Records System and the HR System to maintain who should have login to the university IT systems, and the level of access they have. This system is maintained in the cloud.
- Moodle -- it contains teaching material for all modules and programmes delivered by the university, and supports the running of assessments. Users login using the credentials supplied by the User Authentication System. The Student Records System defines which students should have access to which areas of Moodle. User email addresses are also accessible via Moodle. This system is painted by an external supplier, different to the HR System.
- SharePoint -- it contains most of office files (e.g., Word, Excel) used by the university. Access to SharePoint is managed via the User Authentication System. Users can access different areas based on the level of access. Users can also share files via SharePoint, and synchronise areas of SharePoint in their local OneDrive folders. The university Student Portal also runs from SharePoint. This system is maintained in the cloud.

The following key processes have also been identified:

- Student Recruitment -- most undergraduate students apply for a course via UCAS (the central UK university application system). UCAS forwards data onto the university when an application is made. MSc and overseas students normally use a system integrated into the Student Records System.
- Student Registration -- when students fully register for their course, they must enter their personal details into a system integrated into the Student Records System.
- Staff Appointment -- when a member of staff is appointed, a member of HR enters their details into the HR System from their application form. The new line manager requests login details from IT separately.
- Staff Leaving -- when a member of staff leaves the university, a member of HR will update their record accordingly. The line manager should request the login details be terminated.
- Assessment -- when students submit assessment, marks are entered within Moodle to share directly with the students. For exam boards, lecturers extract the marks from Moodle into an Excel spreadsheet stored on SharePoint. These marks are then entered into the Student Records System by a member of the Academic Services Team.

## Report One

**This report covers the learning outcome *Investigate measures that can be taken by both individuals and organizations including governments to prevent or mitigate the undesirable effects of computer crimes and identity theft.***

The university has asked you to analyse their current systems and processes as defined above and identify potential risks from computer crime. They have asked for a four page report providing the following information:

- Any risks of computer crime to the systems defined above.
- Any risks of computer crime to the processes defined above.
- What measures should the university take to mitigate the risks you have identified.

You will need to create a formal business report with everything compiled into a single document (PDF). The report should use 12-point font in Times New Roman, 1-inch margins, and single line spaced. The report should be properly paged, paragraphed, and sectioned, and include the following sections in order.

1. An introduction to the report, providing its context and motivation.
2. Risks identified for each system defined, detailing why it is a risk.
3. Risks identified for each process defined, detailing why it is a risk.
4. Recommended measures the university should take and how it addresses each of the risks.

The report must be a maximum of four pages.

It is highly recommended that you review the following chapters in the essential course text *Security for Software Engineers* by James N. Helfrich to support your work. The book is available from the library:

- Chapter 02: Classification of Attacks.
- Chapter 04: Social Engineering.
- Chapter 10: Authentication.
- Chapter 11: Access Control.

### Marking Scheme

The following rubric will be used to grade the report.

| **Criteria**                                                 | **Excellent**                                                | **Satisfactory**                                             | **Not Satisfactory**                                         | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Presentation** how well organised is the report.           | Good organisation, points are logically ordered, report order flows together. | Organised, although some points are somewhat jumpy. General flow of report works. | Some organisation points jump around. Flow is unclear.       | Poorly organised. No logical progression. Overall flow is vague. |
| **Discussion** overall level of discussion in the report.    | Excellent overall level of discussion provided.              | Good discussion level provided although unclear or inconsistent in a couple of places. | Discussion is good but lacks clarity and consistency in places. | Discussion is poor and does not provide clarity to the report. |
| **Quality of information** ability to provide details to support the report. | Supporting details specific to subject.                      | Some details are non-supporting to the subject.              | Details are somewhat unclear and do not support the topic.   | Specific details undefined or difficult to find.             |
| **Risks identified** quality and completeness of the risks identified in the report. | Excellent range of risks identified and clearly described.   | Range of risks covers the most obvious ones, and description is generally clear. | Some clear risks not covered and/or level of description is unclear. | No risks identified, or types of risk identified are not suitable for the scenario. |
| **Recommendations** quality and completeness of the recommendations made in the report. | Recommend measures summarises and draws clear, effective methods to address risks identified. | Recommended measures summarises methods although some further clarity on effectiveness is required. | Recommended measures are only remotely related to the risks described. | No recommended measures provided, or measures are inappropriate to the risks identified. |
| **Format** ability to meet the formatting standard defined.  | Report is in the correct format.                             | Report is mostly in the correct format                       | Report has a few formatting issues.                          | Report has many formatting issues or does not meet the guidelines specified. |

## Report Two

**This report covers the learning outcome *Evaluate risks to privacy and anonymity in commonly used applications.***

Continuing from the example above, the university has decided to invest further in the use of office software. They have proposed that the following policies are enacted:

- Academic staff booking system -- academic staff will now use a system that will allow students to view their calendar and schedule meetings with academics to provide targeted support.
- Microsoft Teams -- all staff are now expected to use Microsoft Teams as a communication mechanism between themselves, students, and any external parties. The idea is that since Microsoft Teams integrates with SharePoint then it becomes easier to share documents such as student records.
- Camera and microphone on policy -- to support a good working environment, the university believes all staff and students should have their cameras and microphones on when engaging in virtual communication.
- Student support logging -- to better support students with specific needs, the university wishes to keep a log of these centrally on SharePoint in an Excel file. This log file will contain the student ID and details of their particular support needs.

The university has asked you to analyse these policies and identify potential risks to privacy and anonymity of their staff, students, and external parties they interact with. They have asked for a four page report providing the following information:

- Any risks to privacy and anonymity that may already exist in their systems.
- Any risks to privacy and anonymity that the new policies might cause.
- What measures should the university take to mitigate the risks you have identified.

You will need to create a formal business report with everything compiled into a single document (PDF). The report should use 12-point font in Times New Roman, 1-inch margins, and single line spaced. The report should be properly paged, paragraphed, and sectioned, and include the following sections in order.

1. An introduction to the report, providing its context and motivation.
2. Privacy and anonymity risks identified for the existing systems, detailing why it is a risk.
3. Privacy and anonymity risks identified for the new policies, detailing why it is a risk.
4. Recommended measures the university should take and how it addresses each of the risks.

The report must be a maximum of four pages.

### Marking Scheme

The following rubric will be used to grade the report.

| **Criteria**                                                 | **Excellent**                                                | **Satisfactory**                                             | **Not Satisfactory**                                         | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Presentation** how well organised is the report.           | Good organisation, points are logically ordered, report order flows together. | Organised, although some points are somewhat jumpy. General flow of report works. | Some organisation points jump around. Flow is unclear.       | Poorly organised. No logical progression. Overall flow is vague. |
| **Discussion** overall level of discussion in the report.    | Excellent overall level of discussion provided.              | Good discussion level provided although unclear or inconsistent in a couple of places. | Discussion is good but lacks clarity and consistency in places. | Discussion is poor and does not provide clarity to the report. |
| **Quality of information** ability to provide details to support the report. | Supporting details specific to subject.                      | Some details are non-supporting to the subject.              | Details are somewhat unclear and do not support the topic.   | Specific details undefined or difficult to find.             |
| **Risks identified** quality and completeness of the risks identified in the report. | Excellent range of risks identified and clearly described.   | Range of risks covers the most obvious ones, and description is generally clear. | Some clear risks not covered and/or level of description is unclear. | No risks identified, or types of risk identified are not suitable for the scenario. |
| **Recommendations** quality and completeness of the recommendations made in the report. | Recommend measures summarises and draws clear, effective methods to address risks identified. | Recommended measures summarises methods although some further clarity on effectiveness is required. | Recommended measures are only remotely related to the risks described. | No recommended measures provided, or measures are inappropriate to the risks identified. |
| **Format** ability to meet the formatting standard defined.  | Report is in the correct format.                             | Report is mostly in the correct format                       | Report has a few formatting issues.                          | Report has many formatting issues or does not meet the guidelines specified. |

## Report Three

**This report covers the learning outcome *Describe the issues of trust in interface design with an example of a high and low trust system*.**

The university is worried about ensuring users are properly authenticated to access resources. As such, they are proposing the following changes to how users are authenticated.

1. All users accessing university resources off-campus must use two-factor authentication to do so. The two-factor authentication system uses a password and the approach described below.
2. All on-campus users can access university resources just by using their password. On-campus means logged into a machine either on the university network (e.g., staff offices, labs, library), or on the wireless network.

The two-factor authentication system will work as follows:

- If users have a smart phone, they are encouraged to download the Microsoft Authenticator application which will prompt them to approve when a login attempt on their account occurs.
- If users don't want to use Microsoft Authenticator, they have the following choices:
  - They can receive a code via text to their mobile number.
  - They can receive an automated phone call to approve a login attempt. The user can choose which phone number to use.

The password system will also be updated to use challenge questions for retrieving a lost password. However, the on attempted password retrieval the two-factor authentication system must be used.

The university has asked you to analyse this new system to understand user acceptance of the new authentication approach. In particular, the university is interested in

- The usability of the system.
- User perception of the trustworthiness of the system.
- If the level of trust placed on users is appropriate.

You will need to create a formal business report with everything compiled into a single document (PDF). The report should use 12-point font in Times New Roman, 1-inch margins, and single line spaced. The report should be properly paged, paragraphed, and sectioned, and include the following sections in order.

1. An introduction to the report, providing its context and motivation.
2. Usability issues identified in the new authentication system.
3. Potential issues identified around user perception of trustworthiness of the new authentication system.
4. Potential issues identified around trust given to users by the new authentication system.

The report must be a maximum of four pages.

### Marking Scheme

The following rubric will be used to grade the report.

| **Criteria**                                                 | **Excellent**                                                | **Satisfactory**                                             | **Not Satisfactory**                                         | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Presentation** how well organised is the report.           | Good organisation, points are logically ordered, report order flows together. | Organised, although some points are somewhat jumpy. General flow of report works. | Some organisation points jump around. Flow is unclear.       | Poorly organised. No logical progression. Overall flow is vague. |
| **Discussion** overall level of discussion in the report.    | Excellent overall level of discussion provided.              | Good discussion level provided although unclear or inconsistent in a couple of places. | Discussion is good but lacks clarity and consistency in places. | Discussion is poor and does not provide clarity to the report. |
| **Quality of information** ability to provide details to support the report. | Supporting details specific to subject.                      | Some details are non-supporting to the subject.              | Details are somewhat unclear and do not support the topic.   | Specific details undefined or difficult to find.             |
| **Issues identified** quality and completeness of the issues identified in the report. | Excellent range of issues identified and clearly described.  | Range of issues covers the most obvious ones, and description is generally clear. | Some clear issues not covered and/or level of description is unclear. | No issues identified, or types of risk identified are not suitable for the scenario. |
| **Recommendations** quality and completeness of the recommendations made in the report. | Recommend measures summarises and draws clear, effective methods to address risks identified. | Recommended measures summarises methods although some further clarity on effectiveness is required. | Recommended measures are only remotely related to the risks described. | No recommended measures provided, or measures are inappropriate to the risks identified. |
| **Format** ability to meet the formatting standard defined.  | Report is in the correct format.                             | Report is mostly in the correct format                       | Report has a few formatting issues.                          | Report has many formatting issues or does not meet the guidelines specified. |