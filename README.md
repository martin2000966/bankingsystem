# bankingsystem
# IMT Bank System

Welcome to the IMT Bank System project repository. This project has been successfully completed by Martin Ashraf. Below, you will find essential information about the project and its features.

## Features

### Bank Account

The Bank Account feature includes the following information:

- **Admin Window**: Accessible for administrators.
- **Client Window**: Accessible for clients.

#### Information Required for Bank Account

- **Full Name**: Please enter at least the first four names in the format "First Middle1 Middle2 Last," for example, "Mohamed Salah Hamed Mahrous."

- **Full Address**: Enter the complete address in the format "Street Number, Street Name, City," for example, "6 Hussein Wassef, El-Dokki Street, Giza."

- **National ID**: You must enter a 14-digit National ID number, for example, "29805070100179."

- **Age**: Enter the age of the account holder, for example, "25."

- **Bank Account ID**: This ID will be generated automatically and consists of 10 digits, for example, "1000000000."

- **Guardian**: If the user is less than 21 years old, a guardian is required.

- **Guardian National ID**: Enter a 14-digit National ID number for the guardian, if applicable, for example, "29805070100179."

- **Account Status**: By default, the account status is "Active," but it can also be set to "Restricted" or "Closed." Note that if the account is "Restricted" or "Closed," no actions can be performed on it.

- **Balance**: Enter the account balance, for example, "75000."

- **Password**: A random password will be generated for each account during its creation.

## Project Completion

This project has been successfully completed by Martin Ashraf. All the required features have been implemented, and the project meets the specified requirements. It has passed a group of test cases, demonstrating its functionality and correctness.

## Getting Started

To get started with this project, follow these steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/your-username/imt-bank-system.git
   ```

2. Set up the necessary development environment and dependencies.

3. Run the project locally if needed.

4. Feel free to explore the codebase and project documentation.


## Admin Window

In the IMT Bank System, the admin window consists of three main features, allowing administrators to manage accounts and perform various actions:

### 1. Create New Account

In this feature, administrators can create a new bank account by providing the following parameters:

- **Full Name**: Enter the full name of the account holder.
- **Full Address**: Provide the complete address of the account holder.
- **Age**: Specify the age of the account holder.
- **National ID**: Enter the 14-digit National ID of the account holder.
- **Guardian National ID**: If the account holder is under 21 years old, the system will automatically prompt for the guardian's National ID.
- **Balance**: Set the initial account balance.

Please note that the system will automatically generate the password and bank account ID, and the account status will be set to "Active" upon creation.

### 2. Open Existing Account

In this feature, administrators can access an existing account by providing the Client Bank Account ID. Once an account is opened, administrators can choose from the following sub-features:

- **Make Transaction**: Transfer money to another bank account. Enter the target Bank Account ID and the amount to transfer. Ensure that the amount is less than the client's balance and that both accounts are in the "Active" state for the transaction to be completed.

- **Change Account Status**: Modify the account status. Choose from the following options:
  1. Set Account to Active State
  2. Set Account to Restricted State
  3. Set Account to Closed

- **Get Cash**: Withdraw cash from the account. Enter the desired cash amount to be deducted from the account balance. Ensure that the withdrawal amount is less than the available balance.

- **Deposit in Account**: Add cash to the account. Enter the amount you want to deposit.

- **Return to Main Menu**: Return to the Admin Main Menu.

### 3. Exit the System

This feature allows administrators to exit the admin menu, terminating their session within the system.

### Client Window

To access the Client Window in the IMT Bank System, clients must provide the correct Bank Account ID and Password for authentication. Within this window, clients can perform the following actions:

### 1. Make Transaction

In this feature, clients can initiate money transfers to other bank accounts. The process involves the following steps:

- Enter the target Bank Account ID.
- Specify the amount of money to transfer to the target account.

Please note the following conditions:
- Ensure that the transfer amount is less than the client's available balance, or the transaction won't be completed.
- Transactions cannot be initiated if one of the accounts involved is in the "Restricted" or "Closed" state.

### 2. Change Account Password

In this feature, clients have the ability to change their account password. The process involves the following steps:

- Enter the current (old) password.
- Enter the new password.

### 3. Get Cash

Clients can withdraw cash from their account in this feature. To do so, they need to perform the following steps:

- Specify the amount of cash they want to withdraw.

Ensure the following condition:
- The withdrawal amount should be less than or equal to the account balance to proceed with the transaction.

### 4. Deposit in Account

Clients can add cash to their account in this feature by following these steps:

- Specify the amount they want to deposit.

### 5. Return to Main Menu

This feature allows clients to return


## Contribution

Since this project has been completed, contributions are no longer required. However, if you have any questions or need assistance related to this project, please feel free to reach out to Martin Ashraf.


Thank you for your interest in the IMT Bank System project! If you have any further inquiries, please don't hesitate to contact Martin Ashraf.
