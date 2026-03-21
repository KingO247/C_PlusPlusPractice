/*#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <limits>
#include <sstream>

class TextEditor {
private:
    std::list<std::string> textBuffer;
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;
    std::list<std::string>::iterator currentLine;
    int cursorPosition;
    
    // Save current state for undo
    void saveState() {
        std::string state = serializeBuffer();
        undoStack.push(state);
        // Clear redo stack when new action is performed
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }
    
    // Serialize buffer to string for storage
    std::string serializeBuffer() {
        std::string result;
        for (auto it = textBuffer.begin(); it != textBuffer.end(); ++it) {
            result += *it + "\n";
        }
        return result;
    }
    
    // Deserialize string back to buffer
    void deserializeBuffer(const std::string& state) {
        textBuffer.clear();
        std::string line;
        std::istringstream iss(state);
        while (std::getline(iss, line)) {
            textBuffer.push_back(line);
        }
        if (textBuffer.empty()) {
            textBuffer.push_back("");
        }
        currentLine = textBuffer.begin();
        cursorPosition = 0;
    }

public:
    TextEditor() {
        textBuffer.push_back("");
        currentLine = textBuffer.begin();
        cursorPosition = 0;
    }
    
    void display() {
        std::cout << "\033[2J\033[H"; // Clear screen
        std::cout << "=== Simple Text Editor (Type 'help' for commands) ===\n\n";
        
        int lineNum = 1;
        for (auto it = textBuffer.begin(); it != textBuffer.end(); ++it) {
            if (it == currentLine) {
                std::cout << lineNum << "> " << *it << "|" << std::endl;
            } else {
                std::cout << lineNum << "  " << *it << std::endl;
            }
            lineNum++;
        }
        std::cout << "\nCursor: Line " << (std::distance(textBuffer.begin(), currentLine) + 1) 
                  << ", Position " << cursorPosition << std::endl;
        std::cout << "Undo stack size: " << undoStack.size() 
                  << " | Redo stack size: " << redoStack.size() << std::endl;
        std::cout << "\nEnter command: ";
    }
    
    void insertChar(char c) {
        saveState();
        currentLine->insert(cursorPosition, 1, c);
        cursorPosition++;
    }
    
    void deleteChar() {
        if (cursorPosition > 0) {
            saveState();
            currentLine->erase(cursorPosition - 1, 1);
            cursorPosition--;
        }
    }
    
    void newLine() {
        saveState();
        std::string currentText = *currentLine;
        std::string beforeCursor = currentText.substr(0, cursorPosition);
        std::string afterCursor = currentText.substr(cursorPosition);
        
        *currentLine = beforeCursor;
        auto nextLine = std::next(currentLine);
        textBuffer.insert(nextLine, afterCursor);
        currentLine = nextLine;
        cursorPosition = 0;
    }
    
    void moveUp() {
        if (currentLine != textBuffer.begin()) {
            currentLine--;
            if (cursorPosition > currentLine->length()) {
                cursorPosition = currentLine->length();
            }
        }
    }
    
    void moveDown() {
        auto nextLine = std::next(currentLine);
        if (nextLine != textBuffer.end()) {
            currentLine = nextLine;
            if (cursorPosition > currentLine->length()) {
                cursorPosition = currentLine->length();
            }
        }
    }
    
    void moveLeft() {
        if (cursorPosition > 0) {
            cursorPosition--;
        }
    }
    
    void moveRight() {
        if (cursorPosition < currentLine->length()) {
            cursorPosition++;
        }
    }
    
    void undo() {
        if (!undoStack.empty()) {
            // Save current state to redo stack
            redoStack.push(serializeBuffer());
            
            // Restore previous state
            std::string previousState = undoStack.top();
            undoStack.pop();
            deserializeBuffer(previousState);
        }
    }
    
    void redo() {
        if (!redoStack.empty()) {
            // Save current state to undo stack
            undoStack.push(serializeBuffer());
            
            // Restore next state
            std::string nextState = redoStack.top();
            redoStack.pop();
            deserializeBuffer(nextState);
        }
    }
    
    void run() {
        std::string command;
        while (true) {
            display();
            std::getline(std::cin, command);
            
            if (command == "quit" || command == "exit") {
                break;
            } else if (command == "help") {
                std::cout << "\nCommands:\n";
                std::cout << "  type <text> - Insert text at cursor\n";
                std::cout << "  del - Delete character at cursor\n";
                std::cout << "  newline - Insert new line\n";
                std::cout << "  up/down/left/right - Move cursor\n";
                std::cout << "  undo - Undo last action\n";
                std::cout << "  redo - Redo last undone action\n";
                std::cout << "  quit/exit - Exit editor\n";
                std::cout << "  help - Show this help\n";
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (command.substr(0, 4) == "type") {
                std::string text = command.substr(5);
                for (char c : text) {
                    insertChar(c);
                }
            } else if (command == "del") {
                deleteChar();
            } else if (command == "newline") {
                newLine();
            } else if (command == "up") {
                moveUp();
            } else if (command == "down") {
                moveDown();
            } else if (command == "left") {
                moveLeft();
            } else if (command == "right") {
                moveRight();
            } else if (command == "undo") {
                undo();
            } else if (command == "redo") {
                redo();
            } else if (!command.empty()) {
                // Treat as direct text input
                for (char c : command) {
                    insertChar(c);
                }
            }
        }
    }
};

int main() {
    std::cout << "Welcome to the Simple Text Editor!\n";
    std::cout << "Type 'help' to see available commands.\n\n";
    
    TextEditor editor;
    editor.run();
    
    return 0;
}
*/