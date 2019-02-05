import java.util.*;
import java.lang.*;
import java.text.SimpleDateFormat;
import java.io.*;

public class Main {
	public static void main (String[] args) throws java.lang.Exception
	{
		
		Scanner scanner = new Scanner (System.in);
		int cases = scanner.nextInt();
		for (int i = 0; i < cases; i++) {
			String input = new String();
			input = scanner.next();
			int month = Integer.parseInt(input.substring(0, 2));
			int day = Integer.parseInt(input.substring(2,4));
			int year = Integer.parseInt(input.substring(4,8));
			//System.out.println(day + " " + month + " " + year);
			GregorianCalendar calendar = new GregorianCalendar(year, month - 1, day);
			calendar.add(GregorianCalendar.WEEK_OF_YEAR,40);
			Date date = calendar.getTime();
			int newMonth = calendar.get(GregorianCalendar.MONTH);
			int newDay = calendar.get(GregorianCalendar.DATE);
			int newYear = calendar.get(GregorianCalendar.YEAR);
			//System.out.println(newDay);
			String sign = new String();
			if (newMonth == 0) {
				if (newDay >= 21)
					sign = "aquarius";
				else sign = "capricorn";
				
			} else if (newMonth == 1) {
				if (newDay >= 20)
					sign = "pisces";
				else sign = "aquarius";
				
			} else if (newMonth == 2) {
				if (newDay >= 21)
					sign = "aries";
				else sign = "pisces";
				
			}else if (newMonth == 3) {
				if (newDay >= 21)
					sign = "taurus";
				else sign = "aries";
				
			}else if (newMonth == 4) {
				if (newDay >= 22)
					sign = "gemini";
				else sign = "taurus";
				
			}else if (newMonth == 5) {
				if (newDay >= 22)
					sign = "cancer";
				else sign = "gemini";
				
			}else if (newMonth == 6) {
				if (newDay >= 23)
					sign = "leo";
				else sign = "cancer";
				
			}else if (newMonth == 7) {
				if (newDay >= 22)
					sign = "virgo";
				else sign = "leo";
				
			}else if (newMonth == 8) {
				if (newDay >= 24)
					sign = "libra";
				else sign = "virgo";
				
			}else if (newMonth == 9) {
				if (newDay >= 24)
					sign = "scorpio";
				else sign = "libra";
				
			}else if (newMonth == 10) {
				if (newDay >= 23)
					sign = "sagittarius";
				else sign = "scorpio";
				
			}else if (newMonth == 11) {
				if (newDay >= 23)
					sign = "capricorn";
				else sign = "sagittarius";
				
			}			
			System.out.println(i+1 + " " + String.format("%02d",newMonth+1) + "/" +
					String.format("%02d",newDay) + "/" +
					 String.format("%04d",newYear) + " " + sign);
		}
		scanner.close();
	}

}
