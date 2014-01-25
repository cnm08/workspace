void walkgraph()

{
  TGraphErrors *h1 = new TGraphErrors("/home/cnm08/workspace/walkrand/walker.txt", "\%lg \%lg");
  

  h1 ->GetXaxis()-> SetTitle(" root N "); 
  h1 ->GetYaxis()-> SetTitle(" range ");

  h1->Draw("AP"); 


}