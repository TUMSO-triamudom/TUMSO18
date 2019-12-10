# problem-template
A template for problem designing for competitive programming

## Basic Info
This template is intended to be used with [Polygon](https://polygon.codeforces.com "Polygon").

## Template
```
\documentclass[11pt,a4paper]{article}

\newcommand{\tumsoTime}{<<<YOUR_TIME_HERE>>>}
\newcommand{\tumsoRound}{<<<YOUR_ROUND_HERE>>>}

\usepackage{../tumso}

\begin{document}
<<<YOUR_PROBLEM_STATEMENT_HERE>>>
\end{document}
```

### Details
<<<YOUR_TIME_HERE>>> is the scheduled time. (For example: "16.00 - 19.00" without quotes)  
<<<YOUR_ROUND_HERE>>> is the round number. (For example: 2)  
<<<YOUR_PROBLEM_STATEMENT_HERE>>> is the problem statement. The format is edited from format provided by Polygon.  
The format provided by polygon is as follows:  
```
\begin{problem}{<<<YOUR_PROBLEM_NAME>>>}{standard input}{standard output}{0.25 seconds}{256 megabytes}

...Statement...

\InputFile

...Input...

\OutputFile

...Output...

\Scoring

...Scoring...

\begin{description}

\item[Subtask 1 (37 pts)] ...

\item[Subtask 2 (63 คะแนน)] ...

\end{description}

\Examples

\begin{example}
\exmpfile{example.01}{example.01.a}%
\exmpfile{example.02}{example.02.a}%
\end{example}

\end{problem}
```
The format is not yet accepted by this template. To adapt for this template, you must append "Full Score" to problem configuration:  
```
\begin{problem}{<<<YOUR_PROBLEM_NAME>>>}{standard input}{standard output}{0.25 seconds}{256 megabytes}{<<<YOUR_FULL_SCORE>>>}
```
Note that to display correct example, you must add _example.01_ as input example and _example.01.a_ as output example and so on.  
The file _example.01_ and _example.01.a_ should be contained in the same diretory as the source document.  
And that's all done!  

## Instructions
Create a problem using Polygon.  
Copy the header template and paste into your document.  
Copy problem statement in XeLaTeX from Polygon and insert into <<<YOUR_PROBLEM_STATEMENT_HERE>> in the template.  
Compile and use!  

## Examples
Take a look at [linear](https://github.com/win11905/problem-template/tree/master/linear "linear") example problem.

## Credits
#### Design and Publishing
Sorawee Porncharoenwase  
Pongsaphol Pongsawakul  
#### Documentation (README.md)
Sirawit Pongnakintr  
