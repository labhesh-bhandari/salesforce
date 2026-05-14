public class StudentController {

    public Student__c stu {get; set;}
    public List<Student__c> studentList {get; set;}

    // Constructor
    public StudentController() {
        stu = new Student__c();
        loadStudents();
    }

    // Save new student
    public void saveStudent() {
        insert stu;

        // Clear form after saving
        stu = new Student__c();

        // Refresh table
        loadStudents();
    }

    // Load all students
    public void loadStudents() {

        studentList = [

            SELECT
                Id,
                Name,
                Student__c,
                Class__c,
                Mobile_No__c

            FROM Student__c

        ];
    }

    // Delete student
    public PageReference deleteStudent() {

        String studentId =
            ApexPages.currentPage()
                     .getParameters()
                     .get('id');

        Student__c s = [

            SELECT Id
            FROM Student__c
            WHERE Id = :studentId
            LIMIT 1

        ];

        delete s;

        // Refresh table
        loadStudents();

        return null;
    }
}