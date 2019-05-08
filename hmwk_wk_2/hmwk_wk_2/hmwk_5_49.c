/*
climate change quiz

thomas matthew 06/29/2017
*/

int correct_sum = 0;

void check_correct(int answer, int correct) {
	if (answer == correct) {
		correct_sum+=1;
		printf("obviously correct!\n");
	}
	else {
		printf("what? really? no thats wrong!\n");
	}
	
}

void questions(void) {

	int answer = 0;
	int correct = 0;
	printf("The ____ are ____ at the poles.\n"
		"1) ice caps, expanding\n"
		"2) polar bears, eating people\n"
		"3) ice_caps, melting\n"
		"4) penguins, jumping rope\n");
	correct = 3;
	scanf("     %d", &answer);
	check_correct(answer, correct);
	
	printf(" Sea levels are ____.\n"
		"1) falling\n"
		"2) remaining constant\n"
		"3) rising\n"
		"4) mostly made of waves\n");
	correct = 3;
	scanf("     %d", &answer);
	check_correct(answer, correct);

	printf("As CO2 in the atmosphere increases, oceans become more ____.\n"
		"1) acidic\n"
		"2) hospitable to surfers\n"
		"3) basic\n"
		"4) neutral\n");
	correct = 1;
	scanf("     %d", &answer);
	check_correct(answer, correct);

	printf("The ____ effect occurs when certain gasses, like CO2, trap heat in the atmosphere.\n"
		"1) hothouse\n"
		"2) greenhouse\n"
		"3) funhouse\n"
		"4) helthhous\n");
	correct = 2;
	scanf("     %d", &answer);
	check_correct(answer, correct);

	printf("Climate change will NOT disrupt which of the following:\n"
		"1) macro economics\n"
		"2) food supply\n"
		"3) storm severity\n"
		"4) dank memes\n");
	correct = 4;
	scanf("     %d", &answer);
	check_correct(answer, correct);

	printf("\nyou got this many correct: %d\n", correct_sum);

	if (correct_sum == 5) {
		printf("\nYou're a climate-change expert\n");
	}
	else if (correct_sum == 4) {
		printf("\nYou're almost a climate-change expert\n");
	}
	else  {
		printf("\nYou have some studying to do.\n");
	}
}

void main(void) {
	questions();
}