#include <stdio.h>

int main() {
    // Currency conversion rates
    float usd_to_quetzales = 7.78;
    float euro_to_quetzales = 9.47;
    float usd_to_euro = 0.84;
    
    // Variables to store user input and amount
    int from_currency, to_currency;
    float amount, converted_amount;

    // Loop to keep the program running until the user decides to exit
    while (1) {
        // Display options for currency conversion
        printf("\nMenu de Conversor de Monedas:\n");
        printf("Seleccione el tipo de moneda que desea convertir: \n");
        printf("1. USD\n");
        printf("2. Euro\n");
        printf("3. Quetzal\n");
        
        scanf("%d", &from_currency);

        // Validate user input for from_currency
        if (from_currency < 1 || from_currency > 3) {
            printf("\nOpcion Invalida. Por favor elija entre las opciones 1 y 3.\n");
            continue;
        }

        // Prompt user to select the currency to convert to
        printf("\nSeleccione el tipo de moneda al cual quiere convertir: \n");
        printf("1. USD\n");
        printf("2. Euro\n");
        printf("3. Quetzal\n");
        
        scanf("%d", &to_currency);

        // Validate user input for to_currency
        if (to_currency < 1 || to_currency > 3) {
            printf("\nOpcion Invalida. Por favor elija entre las opciones 1 y 3.\n");
            continue;
        }

        // Get the amount to convert
        printf("\nIngrese la cantidad que desea convertir: ");
        scanf("%f", &amount);

        // Perform currency conversion based on user inputs
        switch (from_currency) {
            case 1:
            
                if (to_currency == 3) {
                    converted_amount = amount * usd_to_quetzales;
                } else if (to_currency == 2) {
                    converted_amount = amount * usd_to_euro;
                } else {
                    converted_amount = amount;
                }
                break;
            case 2:
                if (to_currency == 3) {
                    converted_amount = amount * euro_to_quetzales;
                } else if (to_currency == 1) {
                    converted_amount = amount / usd_to_euro;
                } else {
                    converted_amount = amount;
                }
                break;
            case 3:
                if (to_currency == 1) {
                    converted_amount = amount / usd_to_quetzales;
                } else if (to_currency == 2) {
                    converted_amount = amount / euro_to_quetzales;
                } else {
                    converted_amount = amount;
                }
                break;
        }

        // Display the converted amount
        printf("\nLa cantidad converida es de: %.2f\n", converted_amount);

        // Ask the user if they want to perform another conversion
        printf("\nPresione 1 para salir o cualquier otra tecla para realizar otra conversion.");
        int choice;
        if (scanf("%d", &choice) != 1) {
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        // If the user chooses to exit, break out of the loop
        if (choice == 1) {
            printf("\nConversiones finalizadas. ¡Gracias!\n");
            break;
        }
    }

    return 0;
    
}
