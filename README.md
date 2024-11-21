# kkmensage - A Console Messaging Automation Tool

`kkmensage` is a simple console-based program that simulates a series of actions based on user input, with customizable settings like message sending, random text effects, and visual transitions. It can be used for automating tasks like sending a message repeatedly, creating random effects on the screen, or launching attack modes with different behaviors.

---

## Features

- **Modes**: Two primary operation modes:
  - **Message Mode**: Sends a message a specified number of times with adjustable delays.
  - **Random Case Mode**: Generates random effects on the console screen.
  
- **Attack Modes**: In the second mode, you can simulate different "attack" modes that trigger specific console outputs and actions.

- **Visual Effects**:
  - **Brightness Transitions**: Simulate light effects in the console.
  - **Random Blimp Effects**: Display random stars (`*`) or spaces on the screen, creating an animated effect.

- **User Interface**: 
  - Displays logos and ASCII art to provide a fun, customizable user experience.
  - Option to toggle between graphical modes, including a hacking mode.

- **Flexible Inputs**: Allows the user to define their own messages and timings.

---

## Requirements

- **Windows OS** (due to usage of Windows-specific headers and functions)
- **G++ or MSVC Compiler** (to compile the C++ code)
- **Conio.h** (for `getch()` functionality)
- **Windows.h** (for controlling console behavior, like screen clearing and simulating keypresses)

---

## How to Use

1. **Compile the Program**: 
   - On Windows, use a C++ compiler that supports the `conio.h` and `windows.h` libraries.
   
   ```bash
   g++ kkmensage.cpp -o kkmensage
   ```

2. **Run the Program**:
   - After compiling, run the program in your command line interface (CLI).
   
   ```bash
   ./kkmensage
   ```

3. **Selecting Modes**:
   - The program will prompt you to select the **graphical mode** you wish to use. You can toggle between modes by pressing the appropriate keys:
     - **'q'**: To quit and finalize the operation.
     - **'h'**: To switch to hacking mode.
     - **Left Arrow (`←`)** / **Right Arrow (`→`)**: To switch between message/random or attack modes.

4. **Sending Messages**:
   - You can type a string to send repeatedly and specify how many times you want the message to be sent, along with a delay between each send.

5. **Exit the Program**:
   - The program ends with some fun ASCII art, followed by a thank-you message.

---

## Code Explanation

### Functions Overview:

1. **`randowblimp(int ini, int fim, int probabilityOfStar)`**:
   - Generates a random effect of stars (`*`) and spaces to create a "blimp" effect on the screen.

2. **`brightness_transition(int speed)`**:
   - Gradually increases and decreases the brightness of the stars effect, simulating a light transition.

3. **`limparTela()`**:
   - Clears the console screen using Windows API functions.

4. **`finalização()`**:
   - Displays a sequence of ASCII art to end the program with a nice message.

5. **`renova_interface()`**:
   - Refreshes the screen to show the main logo.

6. **`selectgrafic()`**:
   - Handles the graphical mode selection and switches between different modes, including hacking and graphical effects.

7. **`press(char tecla)`**:
   - Simulates a keypress on the keyboard (used for sending strings and commands).

8. **`toggleCapsLock()`**:
   - Toggles the Caps Lock key on and off, used to simulate text input behavior.

9. **`stringpress(const std::string& str)`**:
   - Presses each character of the given string on the keyboard with a slight delay.

10. **`capturarString(std::string& input)`**:
    - Prompts the user to enter a string and captures the input.

11. **`messagecase()`**:
    - Handles the "message sending" operation, where the user enters a string and specifies how many times it should be sent with a delay.

12. **`randowcase()`**:
    - Placeholder for the random case effect mode.

13. **`attack1()`** and **`attack2()`**:
    - Placeholder functions for different attack modes.

### Main Logic Flow:
- The program prompts the user to select between different modes.
- Depending on the selected mode, it will either send messages, create random effects, or simulate attacks.
- It ends with a fun sequence of ASCII art and a message.

---

## Example

When you run the program, it will display an initial menu for graphical mode selection:

```
  _  ___  __
 | |/ / |/ /                                      
 | ' /| ' / _ __ ___   ___ ___ ___  __ _  __ _  ___ 
 |  ; |  ; | '_ ` _ \ / _ \ __/ __|/ _` |/ _` |/ _ \
 | . \| . \| | | | | |  __\__ \__ \ (_| | (_| |  __/
 |_|\_\_|\_\_| |_| |_|\___|___/___/\__,_|\__, |\___|
  github - Obentemiller                   __/ |     
                                         |___/
```

You can press **`'h'`** to switch to hacking mode or **`'q'`** to finalize and end the program. The program will guide you through the process of message sending, graphical effects, and more.

---

## Contribution

Feel free to fork this repository, create pull requests, and contribute to the development of new features, bug fixes, or improvements.

---

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
