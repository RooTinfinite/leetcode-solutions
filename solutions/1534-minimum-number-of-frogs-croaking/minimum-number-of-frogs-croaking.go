func minNumberOfFrogs(croakOfFrogs string) int {
    c,r,o,a,k:=0,0,0,0,0

	maxFrogs:=0
    
	for _,s:=range croakOfFrogs{
		switch s{
		case 'c':
		   c++
           if c>maxFrogs{
			  maxFrogs = c
		   }
		case 'r':
			r++
			if r>c{
				return -1
			}
		case 'o':
			o++
			if o>r{
				return -1
			}
		case 'a':
			a++
			if a>o{
				return -1
			}
		case 'k':
			k++
			if k>a{
				return -1
			}

			c--
			r--
			o--
			a--
			k--

		default :
		    return -1 
		}
	}

	if c!=0 || r!=0 || o!=0 || a!=0 || k!=0{
		return -1
	}

	return maxFrogs
}