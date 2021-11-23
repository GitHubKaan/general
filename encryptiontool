package main;

import java.util.ArrayList;

public class main {
	public static void main(String[] args) {
		
		//plans: wrong text and own_hash format error (text where number, number where text)
		//infinite long texts
		//bonus in den hash einbauen und automatisch auslesen lassen
		
		System.out.println("> encryption tool");
		
		//__________[optionen]__________
		String text="secret"; //entered text to encrypt (max 10 letters, only letters no space)
		String own_hash=""; //empty or size 10 hash should be inside (only numbers)
		double bonusnumber=0.53; //where the code gets placed in the mega randomizer (0.50 e. g. at 50%'s position) (use value between 0 to 1)
		//die bonusnumber sorgt dafür um zu bestimmen wo der hash in dem megarandomizer ist. 0.50 würde heißen an 50%ster stelle. also in der mitte
		
		
		//__________[individual hash / own hash]__________
		/*
		 * >>> conditions
		 * the hash is always 10 integers long
		 */
		
		int[] collector=new int[9]; //hash array
		
		if (own_hash.length() == 10 || own_hash.isBlank()) { //if own hash has the correct length
			if (own_hash.isBlank()) { //if no own_hash is given, collector will be filled randomly
				System.out.print("new individual hash: ");
				
				for (int i=0; i<collector.length; i++) {
					collector[i]=(int)(int) (Math.random()*(10-1)) + 1; //0 to 9
					
					System.out.print(collector[i]);
				}
			} else { //write own_hash string into collector array if available
				String temp_substring;
				
				System.out.print("old individual hash: ");
				
				for (int i=0; i<collector.length; i++) {
					temp_substring=own_hash.substring(i, i+1);
					collector[i]=Integer.parseInt(temp_substring);
					
					System.out.print(collector[i]);
				}
			}
		} else { //if own hash is to small or long
			System.err.println("wrong hash length");
		}
		System.out.println();
		//collector is now the final hash
		
		
		
		//__________[text encryption]__________
		/*
		 * >>> letter to numbers
		 * a = 1   f = 6   k = 11  p = 16  u = 21  z = 26
		 * b = 2   g = 7   l = 12  q = 17  v = 22
		 * c = 3   h = 8   m = 13  r = 18  w = 23
		 * d = 4   i = 9   n = 14  s = 19  x = 24
		 * e = 5   j = 10  o = 15  t = 20  y = 25
		 *
		 * >>> encryption calculation
		 * 1. letter pos x * hash pos x = ans
		 * 2. get ans size (1 = 1, 2 = 2...)
		 * 3. write size in front of ans
		 * 4. combine: e. g. abj (text), 324 (hash), 1 2 10 (text to integer) => 1314240 (1 3 | 1 4 | 2 40)
		 * 
		 * letter can not be 0 because 0 would delete the number, decryption would be impossible
		 */
		
		ArrayList<String> final_collector = new ArrayList<String>(); //array for final encrypted hash
		
		if (text.length() < 51 && text.length() > 0) { //if text size is between 1 or 50
			int calc_letter_temp = 0;
			int calcvalue;
			
			String[] alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
			
			for (int i=0; i<text.length(); i++) { //loop for every single letter in text
				for (int i2=0; i2<alphabet.length; i2++) { //text to number for calcvalue
					if (text.substring(i, i+1).equals(alphabet[i2])) {
						calc_letter_temp = i2+1; //a = 1
					}
				}
				
				calcvalue = calc_letter_temp * collector[i];
				//System.out.println("for letter " + alphabet[calc_letter_temp-1] + " and hash number " + collector[i] + " solution " + calcvalue);
				
				
				String calcvalue_string = Integer.toString(calcvalue); //calcvalue length calculator
				int calcvalue_length = calcvalue_string.length();
				
				final_collector.add(Integer.toString(calcvalue_length)); //add length of solution to final_collector
				final_collector.add(Integer.toString(calcvalue)); //add solution to final_collector
			}
		} else { //if text size is not between 1 or 50
			System.err.println("wrong text length");
		}
		
		
		
		//__________[final encrypted code]__________
		System.out.print("final code: ");
		for (int i=0; i<final_collector.size(); i++) {
			System.out.print(final_collector.get(i));
		}
		System.out.println();
		System.out.println("Bonus: " + bonusnumber);
		int megarsize = (int) ((Math.random()*(10000-5000)) + 5000);; //randomizer size
		System.out.println("Mega size: " + megarsize);
		
		
		
		System.out.println();
		//__________[mega randomizer]__________

		//megasize length + final_collector length
		System.out.println("> mega randomizer");
		for (int i = 0; i < megarsize; i++) {
			if (i == megarsize*bonusnumber) {
				for (int i2=0; i2<final_collector.size(); i2++) {
					System.out.print(final_collector.get(i2));
				}
			}
			System.out.print((int)(Math.random() * 10));
		}
		System.out.println();
		
		
		
		System.out.println();
		//__________[code decryption]__________
		
		String ent_hash = "311387688"; //enter data here
		String ent_code = "25715132542403140"; //enter data here
		
		ArrayList<String> ent_hash_final = new ArrayList<String>();
		ArrayList<String> ent_code_final = new ArrayList<String>();
		
		if (ent_code.isEmpty() && ent_hash.isEmpty()) {
			System.out.println("> no decryption");
		} else {
			System.out.println("> decryption tool");
			
			//get all substrings from both
			for (int i=0; i<ent_code.length(); i++) {
				ent_code_final.add(ent_code.substring(i, i+1));
			}
			for (int i=0; i<ent_hash.length(); i++) {
				ent_hash_final.add(ent_hash.substring(i, i+1));
			}
			
			
			int counter = 0;
			int calcuint = 0;
			String calcu = "";
			ArrayList<String> temper = new ArrayList<String>();
			ArrayList<Integer> finallet = new ArrayList<Integer>();
			//decrypting all arrays (must start at 1 because alphabet in arraylist starts at 1)
			for (int i=0; i<ent_code.length(); i++) { //kann man bestimmt irg in forschleife reinmachen
				System.out.print("temper - ");
				
				if (ent_code_final.get(i).equals("1")) { 
					temper.add(ent_code_final.get(i+1));
					
					System.out.print(temper.get(0));
				}
				if (ent_code_final.get(i).equals("2")) { 
					temper.add(ent_code_final.get(i+1));
					temper.add(ent_code_final.get(i+2));
					
					System.out.print(temper.get(0) + temper.get(1));
				}
				if (ent_code_final.get(i).equals("3")) { 
					temper.add(ent_code_final.get(i+1));
					temper.add(ent_code_final.get(i+2));
					temper.add(ent_code_final.get(i+3));
					
					System.out.print(temper.get(0) + temper.get(1) + temper.get(2));
				}
				System.out.println();
				
				
				
				for (String calcu2 : temper) { //arraylist to string
					calcu += calcu2;
				}
				
				calcuint = Integer.parseInt(calcu);
				
				int finalc = calcuint / Integer.parseInt(ent_hash_final.get(counter));;
				
				finallet.add(finalc);
				
				System.out.println("alph pos: " + finalc);
				
				finalc = 0;
				calcuint = 0;
				calcu = "";
				i += temper.size();
				temper.clear();
				counter++;
			}
			String[] alphabet = {"quickfix", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
			
			System.out.println();
			System.out.print("final decryption: ");
			for (int i=0; i<finallet.size(); i++) {
				System.out.print(alphabet[finallet.get(i)]);
			}
		}
	}
}




