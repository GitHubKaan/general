 public static void main(String[] args) throws IOException {
        
        String[] alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
        
        String input = "fgtyoprafg";
        ArrayList<String> input_sub = new ArrayList<String>();
        
        for (int i = 0; i < input.length(); i++) {

            input_sub.add(input.substring(i, i + 1));
        }

        int s = 0;
        int high = 0;
        String alph = "";
        for (int i2 = 0; i2 < input.length(); i2++) {
            for (int i = 0; i < alphabet.length; i++) {
                if (input_sub.get(s).equals(alphabet[i])) {
                    if (i > high) {
                        high = i;
                        alph = alphabet[i];
                        s += 1;
                        break;
                    } else {
                        s += 1;
                        break;
                    }
                }
            }
        }
        System.out.println(alph + " is the last letter");
        
        
        int s2 = 0;
        int high2 = 0;
        String alph2 = "";
        for (int i2 = 0; i2 < input.length(); i2++) {
            for (int i = 0; i < alphabet.length; i++) {
                if (input_sub.get(s2).equals(alphabet[i])) {
                    if (i <= high2) {
                        high2 = i;
                        alph2 = alphabet[i];
                        s2 += 1;
                        break;
                    } else {
                        s2 += 1;
                        break;
                    }
                }
            }
        }
        System.out.println(alph2 + " is the first letter");
    }
