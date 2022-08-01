#include<stdio.h>

int main()        
{                                           
    // declare array and variables
	char Map[5][4] = { 'a','#','b','#','c','#','D','#','e','#','#','#','f','G','h','i','J','k','l','m' };
	int choice, i, j, avail_count, sold_count, road_count;
	char ch;

	// First menu
	printf("\n===========================================<<( LAND PLOTS FOR SALE )>>===========================================");      
	printf("\n\n Welcome... This application provides the user with all the functionalities\n required to sell/purchase/consult land plots");
	printf("\n\n----------------<  Menu  >--------------------");
	printf("\n\n(1) Print the map (all land plots).");
	printf("\n(2) Print the count of all available plots in the map.");
	printf("\n(3) Print the count of all sold plots in the map.");
	printf("\n(4) Check the status of a specific land plot.");
	printf("\n(5) Get the price of a specific land plot.");
	printf("\n(6) Buy an available land plot.");
	printf("\n(7) Sell a land plot.");
	printf("\n(8) Quit the application.");
	printf("\n\n\tChoose the number of option: ");
	scanf_s(" %d", &choice);
	printf("-----------------------------------------------\n\n");
	while (choice != 8)   // Menu Loop 
	{
		avail_count = 0, sold_count = 0, road_count = 0;

		switch (choice)
		{
		   case 1:// print the map 
		   {
			   for (i = 0; i < 5; i++)
			   {
				   printf("          -------------------------\n          ");
				   for (j = 0; j < 4; j++)
				   {
					   printf("|  %c  ", Map[i][j]);
				   }
				   printf("|");   
				   if (i == 1) printf("         * small-letter   =>  available land plot");
				   if (i == 2) printf("         * capital-letter =>  sold land plot");
				   if (i == 3) printf("         * hashtag (#)    =>  road (reserved)");
				   printf("\n");
				   
			   }
			   printf("          -------------------------");
		   } break;


		   case 2:// calculate the count of all available land plots
		   {
			   for(i=0; i<5; i++)
				   for (j = 0; j < 4; j++)
					   if (Map[i][j] >= 'a' && Map[i][j] <= 'z') avail_count++;
			   printf("   The count of all available land plots is: %d", avail_count);
		   } break;


		   case 3:// calculate the count of all sold land plots
		   {
			   for (i = 0; i < 5; i++)
				   for (j = 0; j < 4; j++)
					   if (Map[i][j] >= 'A' && Map[i][j] <= 'Z') sold_count++;
			   printf("   The count of all sold land plots is: %d", sold_count);
		   } break;


		   case 4:// check the status of a specific land plot
		   {
			   // read the character from the user
			   int flag = 0;
			   printf("   Please enter the character of land plot >>>(Not case-sensitive)<<< : ");
			   scanf_s(" %c", &ch);
			   if (ch >= 'A' && ch <= 'Z') ch = ch + ('a' - 'A');
			   if (ch >= 'a' && ch <= 'z') flag = 1;
			   while (!flag)
			   {
				   printf("\n   \aInvalid input.. please enter letter character >>(small or capital)<< : ");
				   scanf_s(" %c", &ch);
				   if (ch >= 'a' && ch <= 'z') flag = 1;
			   }

			   // Find the variable in the matrix and keep the value of i,j
			   for (i = 0; i < 5 && flag != 0; i++)
				   for (j = 0; j < 4; j++)
					   if ((Map[i][j] == ch) || (Map[i][j] == ch - ('a' - 'A'))) {flag = 0; break; }
			   --i;

			   // Find the properties of the plot
			   if (flag) printf("\n   This land plot character does not exist.");
			   else
			   {
				   if (i != 4)
				   {
					   if (Map[i + 1][j] == '#') road_count++;
					   else if ((Map[i + 1][j] >= 'A') && (Map[i + 1][j] <= 'Z')) sold_count++;
					   else if ((Map[i + 1][j] >= 'a') && (Map[i + 1][j] <= 'z')) avail_count++;
				   }
				   if (i != 0)
				   {
					   if (Map[i - 1][j] == '#') road_count++;
					   else if ((Map[i - 1][j] >= 'A') && (Map[i - 1][j] <= 'Z')) sold_count++;
					   else if ((Map[i - 1][j] >= 'a') && (Map[i - 1][j] <= 'z')) avail_count++;
				   }
				   if (j != 3)
				   {
					   if (Map[i][j+1] == '#') road_count++;
					   else if ((Map[i][j+1] >= 'A') && (Map[i][j+1] <= 'Z')) sold_count++;
					   else if ((Map[i][j+1] >= 'a') && (Map[i][j+1] <= 'z')) avail_count++;
				   }
				   if (j != 0)
				   { 
					   if (Map[i][j-1] == '#') road_count++;
					   else if (Map[i][j-1] >= 'A' && Map[i][j-1] <= 'Z') sold_count++;
					   else if (Map[i][j-1] >= 'a' && Map[i][j-1] <= 'z') avail_count++;
				   }

				   // print the properties of the plot
				   printf("\n        The status of plot is:\n");
				   if (Map[i][j] >= 'A' && Map[i][j] <= 'Z') printf("\n            -It is sold.\n");
				   else printf("\n            -It is available.\n");
				   printf("            -Its surrounding: (%d available, %d sold, %d roads).", avail_count, sold_count, road_count);
			   }
		   } break;


		   case 5: // get the price of a specific land plot
		   {

			   // read the character from the user
			   int flag = 0;
			   printf("   Please enter the character of land plot >>>(Not case-sensitive)<<< : ");
			   scanf_s(" %c", &ch);
			   if (ch >= 'A' && ch <= 'Z') ch = ch + ('a' - 'A');
			   if (ch >= 'a' && ch <= 'z') flag = 1;
			   while (!flag)
			   {
				   printf("\n   \aInvalid input.. please enter letter character >>(small or capital)<< : ");
				   scanf_s(" %c", &ch);
				   if (ch >= 'a' && ch <= 'z') flag = 1;
			   }

			   // Find the variable in the matrix and keep the value of i,j
			   for (i = 0; i < 5 && flag != 0; i++)
				   for (j = 0; j < 4; j++)
					   if ((Map[i][j] == ch) || (Map[i][j] == ch - ('a' - 'A'))) { flag = 0; break; }
			   --i;

			   // Find the price of the plot
			   if (flag) printf("\n   This land plot character does not exist.");
			   else
			   {
				   if (i != 4)
				   {
					   if (Map[i + 1][j] == '#') road_count++;
				   }
				   if (i != 0)
				   {
					   if (Map[i - 1][j] == '#') road_count++;
				   }
				   if (j != 3)
				   {
					   if (Map[i][j + 1] == '#') road_count++;
				   }
				   if (j != 0)
				   {
					   if (Map[i][j - 1] == '#') road_count++;
				   }

				   // print the price of the plot
				   printf("\n   This plot surrounded by %d roads ==> so its price is : %d $", road_count, 10000 + (int)(10000 * (road_count * 0.1)));

			   }

		   } break;


		   case 6: // Buy a spesific land plot
		   {
			   // read the character from the user
			   int flag = 0;
			   printf("   Please enter the character of land plot >>>(Not case-sensitive)<<< : ");
			   scanf_s(" %c", &ch);
			   if (ch >= 'A' && ch <= 'Z') ch = ch + ('a' - 'A');
			   if (ch >= 'a' && ch <= 'z') flag = 1;
			   while (!flag)
			   {
				   printf("\n   \aInvalid input.. please enter letter character >>(small or capital)<< : ");
				   scanf_s(" %c", &ch);
				   if (ch >= 'a' && ch <= 'z') flag = 1;
			   }

			   // Find the variable in the matrix and keep the value of i,j
			   for (i = 0; i < 5 && flag != 0; i++)
				   for (j = 0; j < 4; j++)
					   if ((Map[i][j] == ch) || (Map[i][j] == ch - ('a' - 'A'))) { flag = 0; break; }
			   --i;

			   // Find the status of the plot
			   if (flag) printf("\n   Sorry.. This land plot character does not exist.");
			   else
			   {
				   if (Map[i][j] >= 'A' && Map[i][j] <= 'Z') printf("\n   Sorry, This plot has been sold.. see the owner if you want it.");
				   else
				   {
					   printf("\n   This plot was available, Do you really want to buy it? (y or Y if yes) : ");
					   scanf_s(" %c", &ch);
					   if (ch == 'y' || ch == 'Y') { printf("\n   Congratulations.. It is yours now."); Map[i][j] = Map[i][j] - ('a' - 'A'); }
					   else printf("\n   Ok, thank you.");
				   }
			   }

		   } break;


		   case 7: // Sell a spesific land plot
		   {
			   // read the character from the user
			   int flag = 0;
			   printf("   Please enter the character of land plot >>>(Not case-sensitive)<<< : ");
			   scanf_s(" %c", &ch);
			   if (ch >= 'A' && ch <= 'Z') ch = ch + ('a' - 'A');
			   if (ch >= 'a' && ch <= 'z') flag = 1;
			   while (!flag)
			   {
				   printf("\n   \aInvalid input.. please enter letter character >>(small or capital)<< : ");
				   scanf_s(" %c", &ch);
				   if (ch >= 'a' && ch <= 'z') flag = 1;
			   }

			   // Find the variable in the matrix and keep the value of i,j
			   for (i = 0; i < 5 && flag != 0; i++)
				   for (j = 0; j < 4; j++)
					   if ((Map[i][j] == ch) || (Map[i][j] == ch - ('a' - 'A'))) { flag = 0; break; }
			   --i;

			   // Find the status of the plot
			   if (flag) printf("\n   Sorry.. This land plot character does not exist.");
			   else
			   {
				   if (Map[i][j] >= 'a' && Map[i][j] <= 'z') printf("\n   Sorry, This plot is not yours, and you cant sell it.");
				   else
				   {
					   printf("\n   This plot is yours, Do you really want to sell it? (y or Y if yes) : ");
					   scanf_s(" %c", &ch);
					   if (ch == 'y' || ch == 'Y')  printf("\n   The sale was successful.");
					   else printf("\n   Ok, thank you.");
				   }
			   }

		   } break;


		   default: printf("    \a Invalid choice.");
		}
	
		// print Menu
		printf("\n___________________________________________________________________________________________________");
		printf("\n\n\t----<  Menu  >----");
		printf("\n\n(1) Print the map (all land plots).");
		printf("\n(2) Print the count of all available plots in the map.");
		printf("\n(3) Print the count of all sold plots in the map.");
		printf("\n(4) Check the status of a specific land plot.");
		printf("\n(5) Get the price of a specific land plot.");
		printf("\n(6) Buy an available land plot.");
		printf("\n(7) Sell a land plot.");
		printf("\n(8) Quit the application.");
		printf("\n\n\tChoose the number of option: ");
		scanf_s(" %d", &choice);
		printf("-----------------------------------------------\n\n");
	}

	printf("\n\n\tThank you... Bye!\n\n\n\n");       // When the user choose 8 (exit)

	return 0;
}