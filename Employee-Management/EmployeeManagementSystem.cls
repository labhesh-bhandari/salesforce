public class EmployeeManagementSystem {

    // 1. Add Employee
    public static void addEmployee(
        Integer empId,
        String empName,
        String email,
        Date birthDate,
        String department
    ) {

        Employee__c emp = new Employee__c();

        emp.Name = empName;
        emp.Emp_ID__c = empId;
        emp.Email__c = email;
        emp.Birth_Date__c = birthDate;
        emp.Department__c = department;

        insert emp;

        System.debug('Employee added successfully.');
    }


    // 2. View Employees
    public static void viewEmployees() {

        List<Employee__c> employees = [

            SELECT
                Id,
                Name,
                Emp_ID__c,
                Email__c,
                Birth_Date__c,
                Department__c

            FROM Employee__c

        ];

        for(Employee__c e : employees){

            System.debug(

                'ID: ' + e.Emp_ID__c +
                ', Name: ' + e.Name +
                ', Email: ' + e.Email__c +
                ', DOB: ' + e.Birth_Date__c +
                ', Department: ' + e.Department__c

            );
        }
    }


    // 3. Update Employee Department
    public static void updateEmployee(
        Integer empId,
        String newDepartment
    ){

        Employee__c emp = [

            SELECT
                Id,
                Name,
                Department__c

            FROM Employee__c
            WHERE Emp_ID__c = :empId
            LIMIT 1

        ];

        emp.Department__c = newDepartment;

        update emp;

        System.debug(

            'Employee updated successfully. ' +
            emp.Name +
            ' moved to ' +
            newDepartment

        );
    }


    // 4. Delete Employee
    public static void deleteEmployee(
        Integer empId
    ){

        Employee__c emp = [

            SELECT Id
            FROM Employee__c
            WHERE Emp_ID__c = :empId
            LIMIT 1

        ];

        delete emp;

        System.debug('Employee deleted.');
    }

}