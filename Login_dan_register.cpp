#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct  User
{
    string username;
    string password;
    string forgotpasword;
    string usernameInput;
    string passwordInput;
    char choice;
    char pilihan;
};

void registerUser(User &user)
{
    cout << "\n====Register====\n";

        cout << "Enter username: ";
        cin.ignore();
        getline(cin, user.username);

    do {
        cout << "Enter 10 character password: \n";
        cin >> user.password;
        if (user.password.length() != 10)
            cout << "Password must be exactly 10 characters!\n";
    } while (user.password.length() != 10);

    cout << "\n=== Registration Complete ===\n";
    cout << "Saved Username : " << user.username << "\n";
    cout << "Saved Password : " << user.password << "\n\n";
}

void savedata(User &user)
{
    ofstream file("user_data.txt");
    if (file.is_open())
    {
        file << user.username << "\n";
        file << user.password << "\n";
        file.close();
        cout << "User data saved successfully.\n";
    }
    else
    {
        cout << "Error saving user data.\n";
    }
}

void forgotPassword(User &user)
{
    cout << "\n====Forgot Password====\n";
    cout << "Enter new password: ";
    cin >> user.forgotpasword;
    user.password = user.forgotpasword;
    cout << "Password reset successful! Your new password is: " << user.forgotpasword << "\n";
}

void loginUser(User &user)
{
    cout << "\n====Login====\n";
    ifstream file("user_data.txt");
    if (file.is_open())
    {
        getline(file, user.username);
        file >> user.password;
        file.close();
    }
    else
    {
        cout << "Error loading user data. Please register first.\n";
        return;
    }
    cout << "Enter username: ";
    cin >> user.usernameInput;
    cout << "Enter password: ";
    cin >> user.passwordInput;
    if (user.usernameInput == user.username && user.passwordInput == user.password)
    {
        cout << "Login successful! Welcome, " << user.username << ".\n";
    }
    else
    {
        cout << "Login failed! Invalid username or password.\n";
        cout << "Forgot password? (Y/n): ";
        cin >> user.choice;
        if (user.choice == 'Y' || user.choice == 'y')
        {
            forgotPassword(user);
            savedata(user);
        }
    }
}



int main()
{
    User user;
    int choice;

   do
   {
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser(user);
        savedata(user);
    }
    else if (choice == 2)
    {
        loginUser(user);
    }
    else if (choice == 3)
    {
        cout << "Exiting program... Goodbye!\n";
    }
    else
    {
        cout << "Invalid choice! Please choose again.\n";
    }
}
   while (choice != 3);
    return 0;
}
