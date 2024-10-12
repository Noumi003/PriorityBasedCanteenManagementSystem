# 🚀 Canteen Queue Management System 🏫

Serving with Priority, Efficiency, and Speed! 🍔

Welcome to the Canteen Queue Management System, where we streamline the process of serving faculty, staff, and students based on priority queues. With time ticking away and hunger rising, our goal is to ensure no one waits longer than they have to! 💪

# 🌟 Key Features

**Priority-based Serving:** The most important (or hungry!) get served first:

  👨‍🏫 Faculty gets the front-of-the-line pass! (Priority: CS, BBA, MASS_COM).
  
  👨‍💼 Staff comes next in line! (Priority: ADMIN, MANAGER, TECHNICIAN).

  🎓 Students—don’t worry, we’ll get to you! (Priority: STUDENT).

**Time Management:** The canteen runs from 8:00 AM to 4:00 PM ⏰. Every service step moves the clock forward by 15 minutes, ensuring an efficient and timely queue system.

**Priority Queueing:** Customers are added based on their category (faculty, staff, students) and their priority level. The higher the priority, the quicker they’re served!

# ⚙️ How It Works
**Create your customers 🧍:** Faculty? Staff? Student? Give them a name and a priority level.

**Queue them up 📝 :** We’ll automatically put them in the correct line based on who they are.

**Serve with speed 🍽️:** Faculty first, then staff, and finally students—unless we’re all out of people to serve!

**Keep an eye on the clock ⏲️:** Time doesn’t stop! The canteen runs on a strict schedule, and we’ll keep you posted on the time after every service!

# 🛠️ Code Breakdown

N**ode Structure:** Represents each customer’s name and their priority in the queue.

**Queue Structure:** Manages the line by keeping track of who's next and serving the highest-priority customer first.

**Time Structure:** Keeps the canteen on schedule, updating the clock after every 15-minute service period.

**Counter Structure:** Handles multiple queues for faculty, staff, and students, ensuring that they are served in the correct order.

# 🎮 Sample Output

Time: 08:00

Canteen is open.

Serving faculty: Sir Abdur Rehman

Time: 08:15

Serving faculty: Sir Umair

Time: 08:30

Serving faculty: Sir Nadeem

Time: 08:45

Serving faculty: Sir Faheem

...

# 🎯 What You Can Customize

**Add More Customers:** Want to simulate a busier canteen? Add more customers with their priorities!

**Change Canteen Hours:** Modify the **isOpen()** function to suit your specific working hours.

**Tweak Priority Levels:** Don’t think the current system is fair? Adjust the priority constants (CS, BBA, etc.) and create your own hierarchy!

# 💡 Ideas for Improvement

**Dynamic User Input:** Let users type in customer names and priorities as the program runs.

**Visual Interface:** Integrate a GUI for a more user-friendly experience.

**More Detailed Scheduling:** Add realistic delays, breaks, or other time-based events!

# 🤝 Contribute

Feel free to fork this project and enhance it! Let’s make queue management fun and efficient!
