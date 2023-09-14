#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "STD_TYPES.H"
#include "accounts.h"
#include "window.h"




void selectWindow(){
    u8 choice=5;
    printf("\n--------welcome to my bank system---------- \n");
    
    
    while(choice !=0 ){
        printf("please select the window needed :\n");
        printf("(0)exit the program     (1)admin window     (2)client window:\n");
        scanf("%hhu",&choice);
        switch (choice)
        {
        case 1:
            openAdminWindow();                   
            break;
        
        case 2:
            openClientWindow();    
            break;
        case 0 :
            break;
        default:
            printf("we get a wrong answer ...please re_enter the system\n");
            break;
        }
    }
}







void openAdminWindow(){
    u8 choice=0 ;
    while(choice != 3 ){
        printf("\n\n\n(((((((Welcome Admin Window))))))\n");
        printf("\nchoose what you need to do :\n");
        printf("    (1)create new account.\n");
        printf("    (2)open an existing account.\n");
        printf("    (3)exit the admin window(going back to the main sys).\n");
        scanf ("%hhu",&choice );
    
        switch (choice)
        {
        case 1:
            createAccount();
            printf("------->DONE CREATING A NEW ACCOUNT\n");
            break;
        
        case 2 :
            u32 ID;
            printf("\nenter the ID :\n");
            scanf("%hd", &ID);
            openAcc(ID);
            break;

        case 3 :
            break;

        default:
            printf("we didn't get the right answer\n");
            break;
        }
    }
}






void openAcc(u32 id){
    Account *myAcc = getAccountByID(id);
    if(myAcc!=NULL){
    u8 choice = 0;
        while (choice != 5 ){          //because 5 el mafroud yeraga3na lel admin window tani 8er kda ana hafdal fl account
            
            printf("\n-----> this is %s 's account :\n",myAcc->fullName);
            printf("pleas choose the operation to make:\n");
            printf("    (1)make transaction\n");
            printf("    (2)change account status\n");
            printf("    (3)get cash\n");
            printf("    (4)deposit money\n");
            printf("    (5)return to the main ADMIN menu and exit the account\n");
            scanf("%hhu",&choice);
            
            switch (choice)
            {
            case 1:
                u32 rec ;
                f64 transactionMoney = 0;
                printf("enter the bankID of the reciever account :\n");
                scanf("%d",&rec);

                printf("\nplease enter the amount to be sent :\n");
                do {
                    scanf("%lf",&transactionMoney);
                    if(transactionMoney<0){
                        printf("you can not send negative value, please try again!\n");
                    }
                }while(transactionMoney<0);
                makeTransaction(id , rec , transactionMoney);
                
                break;

            case 2 :
                setAccStatus(myAcc);
                printf("the status has been changed\n");
                break;

            case 3 :
                getCash(myAcc);
                break;
            
            case 4 :
                deposit(myAcc);
                break;
            
            case 5:
                break;
            
            
            default:
                printf("\nWRONG ANSWER\n");
                break;
            }

        }    

        
    }
}




void openClientWindow(){
    u8 choice=0 ;
    printf("\n\n\n(((((((Welcome client Window))))))\n");
    Account *myAcc = getBankIDAndPassword();
    if (myAcc== NULL){
        return;
    }
    printf("\nWELCOME ,to your account \n");
    while(choice != 5 ){
        printf("please choose the operation to make:\n");
            printf("    (1)make transaction\n");
            printf("    (2)change your password\n");
            printf("    (3)get cash\n");
            printf("    (4)deposit money\n");
            printf("    (5)return to the main  menu and exit the account\n");
            scanf("%hhu",&choice );


            switch(choice ) {
                
                case  1:                //making transfare 
                    printf("\n---->making transfer\n");
                    u32 rec ;
                    f64 transactionMoney = 0;
                    printf("enter the bankID of the reciever account :\n");
                    scanf("%d",&rec);

                    printf("\nplease enter the amount to be sent :\n");
                    do {
                        scanf("%lf",&transactionMoney);
                        if(transactionMoney<0){
                            printf("you can not send negative value, please try again!\n");
                        }
                    }while(transactionMoney<0);
                    makeTransaction(myAcc->bankID, rec , transactionMoney);
                    
                break;

                case 2 :                //change your password
                    printf("\n---->now your setting a new password\n");
                    u8 tempPassword[16]  ;
                    u8 flag ;
                    u8 resume =5;
                   
                    do{
                        flag =0;
                        printf("\nplease enter you old password:\n");
                        fflush(stdin);
                        fgets((tempPassword),16,stdin);
                        fflush(stdin);

                        //if the entered password is similar to the old one
                        for(u16 i =0 ;i<16;i++){
                            if (tempPassword[i] != *(myAcc->password+i) && tempPassword[i] != '\n'){
                                printf("\nwrong password\n");
                                flag = 1 ;          //means that the password is wrong and u should try again 
                                break;
                                
                            }
                            if(tempPassword[i]=='\n'){break;}
                        }
                        if (flag == 1 ){
                            
                            printf ("\nplease select your choice: (0)cancel changing my password  OR  (1)keep trying \n ");
                            scanf("%hhu",&resume);
                            if(resume==0){break;} 
                        }
                    }while(flag==1);
                    if(resume==0){break;} 
                    printf("\nplease enter the new password :\n");
                    fflush(stdin);
                    fgets(myAcc->password,16,stdin);
                    fflush(stdin);
                    printf("\nthe new password has been set successfully.\n\n\n");
                break;

                case 3 :
                    getCash(myAcc);
                    printf("withdraw is done successfully\n\n");
                break;
            
                case 4 :
                    deposit(myAcc);
                    printf("deposit is done successfully\n\n");
                break; 

                case 5 : break;

                default: printf("\nwe recieved a wrong answer please try again\n");


                    

            }


    }
}





Account *getBankIDAndPassword(){
    u32 tempID ;
    u8 tempPass [16];
    printf("\nplease enter your bank ID :\n");
    scanf("%d",&tempID);
    Account *tempAcc= getAccountByID(tempID) ;
    if (tempAcc == NULL){
          printf("wrong id\n");
        return NULL;
    }
    printf("\nplease enter your password:\n");
    fflush(stdin);
    fgets((tempPass),16,stdin);
    fflush(stdin);
    for(u16 i =0 ;i<16;i++){
        if (tempPass[i] != *(tempAcc->password+i) && tempPass[i] != '\n'){
            printf("\nwrong password\n");
            return NULL;
        }
        if(tempPass[i]== '\n' || *(tempAcc->password+i)==0){
            break;
        }
    }
    return tempAcc;


}

