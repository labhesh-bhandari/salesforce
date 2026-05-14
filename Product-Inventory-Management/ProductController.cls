public class ProductController {

    public Product_Inventory__c prod {get; set;}

    public List<Product_Inventory__c> productList {get; set;}

    public Boolean isEditMode {get; set;}


    // Constructor
    public ProductController(){

        prod = new Product_Inventory__c();

        isEditMode = false;

        loadProducts();
    }


    // CREATE
    public void saveProduct(){

        insert prod;

        prod = new Product_Inventory__c();

        loadProducts();
    }


    // READ
    public void loadProducts(){

        productList = [

            SELECT
                Id,
                Name,
                Serial_No__c,
                Quantity__c,
                Manufacture_Date__c,
                Expiry_Date__c

            FROM Product_Inventory__c

        ];
    }


    // LOAD RECORD FOR UPDATE
    public PageReference editProduct(){

        String productId =
            ApexPages.currentPage()
                     .getParameters()
                     .get('id');


        prod = [

            SELECT
                Id,
                Name,
                Serial_No__c,
                Quantity__c,
                Manufacture_Date__c,
                Expiry_Date__c

            FROM Product_Inventory__c
            WHERE Id = :productId
            LIMIT 1

        ];

        isEditMode = true;

        return null;
    }


    // UPDATE
    public void updateProduct(){

        update prod;

        prod = new Product_Inventory__c();

        isEditMode = false;

        loadProducts();
    }


    // DELETE
    public PageReference deleteProduct(){

        String productId =
            ApexPages.currentPage()
                     .getParameters()
                     .get('id');


        Product_Inventory__c p = [

            SELECT Id
            FROM Product_Inventory__c
            WHERE Id = :productId
            LIMIT 1

        ];

        delete p;

        loadProducts();

        return null;
    }

}