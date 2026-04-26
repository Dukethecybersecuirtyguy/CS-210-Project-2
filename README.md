1.Summarize the project and what problem it was solving.

The issue of recognizing how compound interest might help your money grow is resolved by the Airgead Banking project. In order to view a year-over-year projection of their balances, consumers can enter their initial investment, monthly deposits, and interest rates in an interactive terminal application. This enables students to comprehend how long-term savings will impact their financial situation.

2.What did you do particularly well?

I successfully divided the application logic into distinct header (.h) and implementation (.cpp) files. By placing the math and display procedures in a separate class, I was able to keep the main() execution loop extremely neat and structured.

3.Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I would improve the code by adding robust execution logging and tightening the input cleaning. As of right now, the application depends on the user entering the appropriate data. If the software included comprehensive bounds checking and type validation, it would be far more stable and secure. This would prevent unexpected input from causing the application to crash.

4.Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

To get the output to display precisely two decimal places and line up in the terminal columns, some trial and error was required. I experimented with various formatting settings and thoroughly read the official C++ instructions for the <iomanip> library to get around this. Standard library documentation websites will now always be a part of my problem-solving process.


6.What skills from this project will be particularly transferable to other projects or course work?

The concepts of object-oriented programming that are employed here can be applied in numerous other contexts. You can build secure backend scripts and perform infrastructure tasks without making your system more vulnerable if you understand how to manage data structures and safely encapsulate functionality.

7.How did you make this program maintainable, readable, and adaptable?

To make things easier to manage, I used more descriptive camelCase variable names, such as monthlyDeposit rather than just md. Additionally, I included thorough comments explaining the arithmetic utilized in the code. This eliminates the need for future developers or operations engineers to do the arithmetic themselves and allows them to grasp the concept immediately.
