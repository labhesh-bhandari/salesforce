public class EmailNotificationSystem {

    
    // 1. Send email without attachment
    public static void sendEmail(

        String recipientEmail,
        String subject,
        String messageBody

    ){

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


        Messaging.sendEmail(

            new Messaging.SingleEmailMessage[] {
                mail
            }

        );


        System.debug(
            'Email sent successfully.'
        );
    }



    // 2. Send email with attachment
    public static void sendEmailWithAttachment(

        String recipientEmail,
        String subject,
        String messageBody,

        String fileName,
        String fileContent

    ){

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



        // Create attachment
        Messaging.EmailFileAttachment attachment =
            new Messaging.EmailFileAttachment();


        attachment.setFileName(
            fileName
        );


        attachment.setBody(

            Blob.valueOf(
                fileContent
            )

        );



        // Attach file
        mail.setFileAttachments(

            new Messaging.EmailFileAttachment[] {
                attachment
            }

        );



        // Send mail
        Messaging.sendEmail(

            new Messaging.SingleEmailMessage[] {
                mail
            }

        );


        System.debug(
            'Email with attachment sent successfully.'
        );
    }

}