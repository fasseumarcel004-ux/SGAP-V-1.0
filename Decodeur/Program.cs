/*using System;
using System.Text;
using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;

class Program{
    static void main(){
        string chaine = "";
        string resultat = ESAB46_Decode(chaine);
        Console.WriteLine("Le mot de passe est : " + resultat); 
    }
    static string ESAB46_Decode(string input){
        string text = "ABCDqrs456tuvNOPwxyz012KLM3789=+QRSTUVWXYZabcdefghijklmnopEFGHIJ/";
        StringBuilder stringBuilder = new StringBuilder();
        checked
        {
            int num2 = default(int);
            do
            {
                int[] array = new int[4];
                int[] array2 = new int[3] { 0, 0, 0 };
                int num = 0;
                int num3;
                do
                {
                    array[num] = text.IndexOf(input[num2]);
                    num2++;
                    num++;
                    num3 = 3;
                }
                while (num <= num3);
                array2[0] = (array[0] << 2) | (array[1] >> 4);
                array2[1] = ((array[1] & 0xF) << 4) | (array[2] >> 2);
                array2[2] = ((array[2] & 3) << 6) | array[3];
                stringBuilder.Append((char)array2[0]);
                if (array[2] != 64)
                {
                    stringBuilder.Append((char)array2[1]);
                }
                if (array[3] != 64)
                {
                    stringBuilder.Append((char)array2[2]);
                }
            }
            while (num2 < input.Length);
            return stringBuilder.ToString();
        }
    }
}
*/
