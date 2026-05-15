# Employee Management System using Salesforce Lightning App Builder

## Objective
Develop an Employee Management application in Salesforce using Lightning App Builder (Drag and Drop) with field validations.

The system validates:

- Employee Name cannot be empty and must contain at least 3 characters.
- Employee ID must be greater than 0 and unique.
- Salary must be between 10,000 and 500,000.
- Email must follow valid email format.
- Department must be selected.
- Joining Date cannot be a future date.

---

# Step 1: Create Custom Object

1. Go to:

   Setup → Object Manager → Create → Custom Object

2. Enter:

   Label = Employee  
   Plural Label = Emps  
   Object Name = Employee  
   Record Name = Employee Name  
   Data Type = Text

3. Click Save.

---

# Step 2: Create Fields

Go to:

Employee → Fields & Relationships → New

Create the following fields:

## 1. Employee ID

- Data Type = Number
- Label = Employee ID
- Length = 10
- Decimal Places = 0
- Check **Unique**

Click Save.

## 2. Salary

- Data Type = Currency
- Label = Salary

Click Save.

## 3. Email

- Data Type = Email
- Label = Email

Click Save.

## 4. Department

- Data Type = Picklist
- Label = Department

Values:

HR  
IT  
Finance  
Marketing

Check **Required**

Click Save.

## 5. Joining Date

- Data Type = Date
- Label = Joining Date

Click Save.

---

# Step 3: Create Validation Rules

Go to:

Employee → Validation Rules

---

## Validation Rule 1: Employee Name

Click New.

Rule Name:

Employee_Name_Validation

Formula:

LEN(Name) < 3

Error Message:

Employee Name must contain at least 3 characters.

Click Save.

---

## Validation Rule 2: Employee ID

Click New.

Rule Name:

Employee_ID_Validation

Formula:

Employee_ID__c <= 0

Error Message:

Employee ID must be greater than 0.

Click Save.

---

## Validation Rule 3: Salary

Click New.

Rule Name:

Salary_Validation

Formula:

OR(
    Salary__c < 10000,
    Salary__c > 500000
)

Error Message:

Salary must be between 10000 and 500000.

Click Save.

---

## Validation Rule 4: Joining Date

Click New.

Rule Name:

Joining_Date_Validation

Formula:

Joining_Date__c > TODAY()

Error Message:

Joining Date cannot be in future.

Click Save.

---

# Step 4: Create Lightning Record Page

1. Search:

   Lightning App Builder

2. Click:

   New

3. Select:

   Record Page

4. Enter:

   Label = Employee Page  
   Object = Employee

5. Click Done.

---

# Step 5: Drag and Drop Record Detail

1. Search:

   Record Detail

2. Drag **Record Detail** to the center section.

3. Click Save.

---

# Step 6: Activate the Page

1. Click:

   Activation

2. Select:

   App Default

3. Select:

   Employee Data Management

4. Click Save.

---

# Step 7: Create Custom Object Tab

1. Search:

   Tabs

2. Open **Tabs**

3. Under **Custom Object Tabs**, click:

   New

4. Select object:

   Employee

5. Select any icon.

6. Click:

   Next → Next → Save

---

# Step 8: Configure Lightning App

1. Search:

   App Manager

2. Find:

   Employee Data Management

3. Click:

   Dropdown → Edit

---

## Add User Profile

1. Click:

   User Profiles

2. Select:

   System Administrator

3. Move it to Selected Profiles.

---

## Add Navigation Item

1. Click:

   Navigation Items

2. Search:

   Emps

3. Move it to Selected Items.

4. Click Save.

---

# Step 9: Run the Application

1. Click the **9 dots (App Launcher)**.

2. Search:

   Employee Data Management

3. Open the app.

4. Click:

   Emps

5. Click:

   New

6. Enter employee details.

7. Click Save.

---

# Testing Validations

## Test 1: Invalid Name

Input:

Al

Expected:

Employee Name must contain at least 3 characters.

---

## Test 2: Invalid Employee ID

Input:

0

Expected:

Employee ID must be greater than 0.

---

## Test 3: Invalid Salary

Input:

5000

Expected:

Salary must be between 10000 and 500000.

---

## Test 4: Invalid Email

Input:

abc

Expected:

Email format error.

---

## Test 5: Future Joining Date

Input:

Tomorrow’s date

Expected:

Joining Date cannot be in future.

---

## Test 6: Duplicate Employee ID

Input:

Existing Employee ID

Expected:

Duplicate value error.

---

# Result

Employee Management System created successfully using Salesforce Lightning App Builder with field validations.