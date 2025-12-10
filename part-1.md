# **Part 1: Git and GitHub Basics**

## **1. Introduction**

This section introduces the essential workflow used throughout the course for managing and submitting programming assignments.
You will learn:

* how to use **Git** for version control,
* how **GitHub** stores your code online, and
* how **GitHub Classroom** distributes and collects your assignments.

# **2. Fundamental Concepts**

Before using Git, understand the following key terms.

### **2.1 Repository**

A project folder tracked by Git.
It contains your source code and the complete history of all changes.

### **2.2 Local Repository**

The version of the repository stored on your computer after cloning it.

### **2.3 Remote Repository**

The version stored on GitHub’s servers.

### **2.4 Commit**

A snapshot of your code at a specific point in time.
Each commit should represent a meaningful change.

### **2.5 Staging Area**

A temporary area where changes are placed before committing.
Files must be staged with:

```
git add <file>
```

### **2.6 Push and Pull**

* `git push` uploads your local commits to GitHub.
* `git pull` downloads updates from GitHub to your computer.

### **2.7 GitHub Classroom**

A platform used to distribute assignments and collect submissions.
Each student receives a **private repository** when accepting an assignment.

# **3. Step-by-Step Workflow**

## **Step 1 — Accept the Assignment**

1. Open the GitHub Classroom link from your instructor.
2. Click **“Accept Assignment.”**
3. GitHub Classroom will create your private repository.
4. Copy your repository URL, for example:
   `https://github.com/<organization>/lab1-<username>`


## **Step 2 — Clone the Repository**

Open a terminal and run:

```bash
git clone <your-repository-url>
cd <repository-folder>
```

This creates a **local copy** of your assignment.


## **Step 3 — Make a Small Edit**

To test your setup:

1. Open `README.md` in an editor.
2. Add the line:

   ```
   This is my first Git modification.
   ```
3. Save the file.


## **Step 4 — Check File Status**

```bash
git status
```

This shows which files were modified or added.


## **Step 5 — Stage Your Changes**

Stage a specific file:

```bash
git add README.md
```

Or stage all modified files:

```bash
git add .
```

## **Step 6 — Commit Your Work**

```bash
git commit -m "Add initial edit to README"
```

Commit messages should briefly describe what you changed.


## **Step 7 — Push Your Work (Submission)**

```bash
git push
```

This uploads your commits to GitHub.
The **latest push is your submission** in GitHub Classroom.

Verify your submission by visiting your repository page on GitHub.


# **4. Standard Workflow for All Labs**

You will repeat this cycle throughout the course:

1. Modify your code.

2. Compile and test your program.

3. Stage your changes:

   ```bash
   git add .
   ```

4. Commit your changes:

   ```bash
   git commit -m "Describe your change here"
   ```

5. Push your work:

   ```bash
   git push
   ```

This workflow mirrors real-world software development practices.


# **5. Essential Git Commands**

```
git status        # Show changed files
git add <file>    # Stage a specific file
git add .         # Stage all changes
git commit -m ""  # Save a snapshot
git push          # Upload commits to GitHub
git pull          # Get updates from GitHub
```

