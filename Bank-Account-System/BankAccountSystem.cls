public class BankAccountSystem {

    // 1. Add Customer
    public static void addCustomer(
        Integer customerId,
        String customerName,
        String phone,
        String email,
        String accountNumber,
        Decimal balance
    ){

        Customer__c c = new Customer__c();

        c.Name = customerName;
        c.Customer_ID__c = customerId;
        c.Phone_Number__c = phone;
        c.Email__c = email;
        c.Account_Number__c = accountNumber;
        c.Account_Balance__c = balance;

        insert c;

        System.debug('Customer added successfully.');
    }


    // 2. View Customers
    public static void viewCustomers(){

        List<Customer__c> customers = [

            SELECT
                Name,
                Customer_ID__c,
                Phone_Number__c,
                Email__c,
                Account_Number__c,
                Account_Balance__c

            FROM Customer__c

        ];

        for(Customer__c c : customers){

            System.debug(

                'ID: ' + c.Customer_ID__c +
                ', Name: ' + c.Name +
                ', Phone: ' + c.Phone_Number__c +
                ', Email: ' + c.Email__c +
                ', Account: ' + c.Account_Number__c +
                ', Balance: ' + c.Account_Balance__c

            );
        }
    }


    // 3. Update Balance
    public static void updateBalance(
        Integer customerId,
        Decimal newBalance
    ){

        Customer__c c = [

            SELECT
                Id,
                Name,
                Account_Balance__c

            FROM Customer__c
            WHERE Customer_ID__c = :customerId
            LIMIT 1

        ];

        c.Account_Balance__c = newBalance;

        update c;

        System.debug(

            'Balance updated for ' +
            c.Name

        );
    }


    // 4. Delete Customer
    public static void deleteCustomer(
        Integer customerId
    ){

        Customer__c c = [

            SELECT Id
            FROM Customer__c
            WHERE Customer_ID__c = :customerId
            LIMIT 1

        ];

        delete c;

        System.debug('Customer deleted.');
    }

}