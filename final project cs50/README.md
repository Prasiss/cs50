# YOUR PROJECT TITLE
#### Video Demo:  https://youtu.be/-PvIhBI-NTQ
#### Description:

My Task Manager is created in Flask, a secure, user-friendly tool to handle tasks: homework, chores, or even personal projects. I have used in this project everything learned in CS50x, from Flask to SQL to password hashing. It's my version of a smart notebook and safer than using sticky notes.

Let's start with the security part. The app makes sure you can't just walk in and see somebody else's to-do list. When you open the site, you are going to have to log in with a username and password. But here is the kicker: the password isn't stored like a sitting duck. I used "password hashing," a technique that changes the password into something unrecognizable. Even if someone breaks into the database, he will only find scrambled characters. No password leaks here!

If you're new to the site, you can register by simply entering your username and password. If your password does not match the confirmation field, it will be flagged by the app faster than you are able to say "oops." Once you're logged in, your tasks await; you'll be taken directly to your personalized dashboard.

After logging in, you're taken to your dashboard where all your tasks are listed. It's like your to-do list, but better: organized and digitized. The dashboard would show the following information that is important: the name of the task so that you won't forget what it was, due dates because deadlines are your best friend or worst enemy, priority because some things really need to be done NOW, and a progress bar showing whether it's been completed. Yes, I added a progress bar for those of us who love marking off tasks and feeling accomplished.

Behind the scenes, everything gets stored in an SQL database so that your tasks are kept safe and always there when you need them, be it after procrastination or the day you finally get organized. We've all been there.

Got a new task? There is an "Add Task" page where you can fill in the details of the task. I added some validations so that you are not able to enter half a task. You cannot submit it until you have entered the name, description, deadline, priority, and completion status, so you will never forget the important stuff.

It will get added; it is then saved into the database, to your portfolio page, and at the instance when you actually complete that particular task, mark as "done". In case a field isn't filled in, it would still say, "Hey, you've missed something." After all, it is often said: in task management, the devil's in the details.

Now, I am no designer, but I do know nobody wants to look at a dull webpage. That's why I used Bootstrap; this way, the app looks great on any device, from phones to desktops. The layout will adapt to the screen size so that you can check your tasks in style.

I also added JavaScript in the app to make it a bit more interactive. Like, for example, when you forget to fill in a field while adding tasks, a message will pop up telling you what's missing. It's like having a personal assistant who's always looking out for you but without the salary.

Security doesn't end when you log in. When you're through and log out, the app clears everything from the session. This is so that when you step away from the computer, no one can see your tasks. After logging out, you're taken back to the home page where no one can peek at your to-do list.

Building this app was a great experience in learning. It wasn't all about coding-actually, it was creating something for people that could help them keep themselves organized and on top of things. Flask, SQL, and all the features about security joined to create a project of which I am very proud. Whether homework, errands, or personal goals you're managing, the Task Manager helps guide you along. And if nothing else, it's a reminder that with the right tools, you can be as organized as you like-one task at a time. And that's progress!
