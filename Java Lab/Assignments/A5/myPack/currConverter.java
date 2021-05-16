/*1. Create a package named myPack.CurrConvertor to implement the currency converter
(Dollar to INR, EURO to INR, Yen to INR and vice versa). Write a java program which uses this
package to convert the given currency into other currency type.
Use the pre-defined exception java.lang.NumberFormatException (checked) to throw
the error whenever the given input currency is not in the required format.*/

package myPack;

public class currConverter
{
	public float DollortoINR(float a)
	{
		return a*71.23f;
	}
	public float EurotoINR(float a)
	{
		return a*78.93f;
	}
	public float YentoINR(float a)
	{
		return a*10.11f;
	}
	public float INRtoDollor(float a)
	{
		return a/71.23f;
	}
	public float INRtoEuro(float a)
	{
		return a/78.93f;
	}
	public float INRtoYen(float a)
	{
		return a/10.11f;
	}
}
