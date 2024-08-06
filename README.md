
# Typing Tutor

## Tech Stack : C, File I/O

## Introduction
This university project displaying my proficiency in C Programming language through an interactive command-line tool aimed at improving one's typing abilities, speed, and precision. 
This tool includes a variety of lessons that teach the use of various keyboard keys. 
A built-in testing feature where user can test thier typing skills with each result stored for future reference. This feature provides a convenient way to track and visualise progress over time.

## User Registration
![image](https://github.com/user-attachments/assets/b78e1ba3-e86d-4e78-b765-4d0872049ef8)

If you are new User select 1. 


You can register yourself by providing a unique Username and Password. User's username and encrypted password are stored in **userlist.dat** in the root directory of the project.<br/>


If you are an existing User Select 2. <br/>

![image](https://github.com/user-attachments/assets/2a30fd6b-da95-4fab-8452-135e687538b1)


## Home Screen
Once the user has signed into the application, they are token to  **Home**  Screen containing three menu items as shown in the following screenshot.

![image](https://github.com/user-attachments/assets/f51de506-b35c-4411-95ec-55ab54fbac9c)


## Lessons
![image](https://github.com/user-attachments/assets/6fe8c434-7246-45ea-be15-be1b2ba70999)

Almost for all the keys on the Keyboard, there is lesson tailored. 

### Each lesson has three stages
1. Introduction: Introduction about the lesson and it contains instructions for each of the keyboard key introduced in this lesson. The instructions tells the user how to press the key. 
2. Practice : Here user can practice.
3. Test : Once user has gained enough confidence to visit next lesson, they can take test before jumping to next lesson. 

![image](https://github.com/user-attachments/assets/1b1b5e0a-381c-463b-b42a-d63eb9bee366)


#### For example, the below given screenshot is taken from the Introduction Stage of Home Row Keys Lesson
![image](https://github.com/user-attachments/assets/252254c7-94a7-4375-b089-d87eb3201e9e)

### Practice Stage

![image](https://github.com/user-attachments/assets/fa27b521-613a-4020-8be0-2c2c232d001a)

In the above screenshot, the cursor is currently pointing at **a**. Unless the user presses small **a**, the cursor doesn't move forward. For each incorrect press, the computer beeps.

The data is rendered from the files **/files/test/** directory. This directory contains text files for each of the lesson. These files are easily editable as they are just text file.

### Test
![image](https://github.com/user-attachments/assets/404a0b85-8fc6-46bc-ab68-58aa6d8613df)


## Grand Test
Once the user has completed all the lessons, they can test their typing skills by visiting **Test** Section

![image](https://github.com/user-attachments/assets/c0aff9e9-5a6e-41ef-8488-0f39236569ed)

Currently we have only two tests. You can add more test cases just by adding **text** files under **/files/grandTest/** directory. 

Each test report can then been seen under the Report Section

The following screenshot has been taken after appearing the **Hubble Space Telescope** Grand Test

![image](https://github.com/user-attachments/assets/a86d0bf4-08b6-4919-8962-f0ef6f741826)


## Report
It shows consolidated View of all the **Grand Tests** the user has appeared. 
![image](https://github.com/user-attachments/assets/6693b6fe-d8b9-41cf-ad07-3f7bb0a769c9)

