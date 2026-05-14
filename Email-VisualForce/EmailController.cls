public class EmailController {

    public String recipientEmail {get; set;}
    public String subject {get; set;}
    public String messageBody {get; set;}

    
    // Uploaded file
    public Blob uploadedBody {get; set;}
    public String uploadedFileName {get; set;}


    public PageReference sendEmail(){


        // Validate email
        if(
            recipientEmail == null ||

            !Pattern.matches(

                '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$',

                recipientEmail
            )
        ){

            ApexPages.addMessage(

                new ApexPages.Message(

                    ApexPages.Severity.ERROR,

                    'Invalid Email Address'

                )

            );

            return null;
        }



        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();


        mail.setToAddresses(

            new List<String>{
                recipientEmail
            }

        );


        mail.setSubject(
            subject
        );


        mail.setPlainTextBody(
            messageBody
        );



        // If user uploaded file
        if(
            uploadedBody != null &&
            uploadedFileName != null
        ){

            Messaging.EmailFileAttachment attachment =
                new Messaging.EmailFileAttachment();


            attachment.setFileName(
                uploadedFileName
            );


            attachment.setBody(
                uploadedBody
            );


            mail.setFileAttachments(

                new Messaging.EmailFileAttachment[]{
                    attachment
                }

            );
        }



        Messaging.sendEmail(

            new Messaging.SingleEmailMessage[]{
                mail
            }

        );



        ApexPages.addMessage(

            new ApexPages.Message(

                ApexPages.Severity.CONFIRM,

                'Email sent successfully.'

            )

        );


        return null;
    }

}