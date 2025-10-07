class Spreadsheet {
    int col = 0;
    int rows = 0;
    TreeMap<String, Integer> map = new TreeMap<>();

    public Spreadsheet(int rows) {
        col = 26;
        this.rows = rows;
    }

    public void setCell(String cell, int value) {
        map.put(cell, value);
    }

    public void resetCell(String cell) {
        if (map.containsKey(cell)) {
            map.put(cell, 0);

        }
    }

    public int getValue(String formula) {
        int sum=0;
	String res[]=formula.split("\\+");
	String firsts=res[0].substring(1);
	String secondString=res[1];
	if(map.containsKey(firsts))
	{
		sum+=map.get(firsts);
	}
	else {
		if (firsts.chars().anyMatch(ch -> ch >= 'A' && ch <= 'Z')) {
		   sum+=0;
		}
		else {
			sum+=Integer.valueOf(firsts);
		}
		
	}
	//System.out.print(secondString);
	if(map.containsKey(secondString))
	{
		sum+=map.get(secondString);
	}
	
	else {
		//System.out.println("here");
		if (secondString.chars().anyMatch(ch -> ch >= 'A' && ch <= 'Z')) {
		   sum+=0;
		}
		else {
			//System.out.println("here");
			sum+=Integer.valueOf(secondString);
		}
	}

        return sum;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */