#include <TMath.h>
void sum()
{
  TFile *f = TFile::Open("Fits.root", "READ");
  
  TH1F* myhist = (TH1F*)f->Get("hfsomme"); 
  TF1 *mix = new TF1 ("mix", "[0] +[1]*x + [2]*x*x + [3]*exp(-[4]*x)+  gaus(5)", 0,55);
  
  mix->SetParLimits(0, -20, 20);
  mix->SetParLimits(1, -20, 20);
  mix->SetParLimits(2, -20, 20);
  mix->SetParLimits(3, 65, 200);
  mix->SetParLimits(4, -10, 10);
  mix->SetParLimits(5, 50, 200);
  mix->SetParLimits(6, 15,30);
  mix->SetParLimits(7, 5, 15);
  

  TF1* myexpo = new TF1("myexpo", "113*exp(-0.26*x)", 0, 50);
  TF1* mypol  = new TF1("mypol", "6.37656 -3.62662*x + 0.161584*x*x", 0, 50);
  TF1* mygauss = new TF1("mygauss", "-10+117.025*exp(-0.5*((x-22.4666)/6.70508)^2)",0,50);
  TF1* mymix= new TF1("mymix", "10+113*exp(-0.26*x)+6.37656 -3.62662*x + 0.161584*x*x-10+117.025*exp(-0.5*((x-22.4666)/6.70508)^2)", 0, 50);

  myhist -> Fit("mix"); 
  myhist->Draw();
  myexpo->SetLineColor(kBlue);
  myexpo->Draw("SAME");
  
  mypol->SetLineColor(kCyan);
  mypol->Draw("SAME");

  mygauss -> SetLineColor(kGreen);
  mygauss -> Draw("SAME");

  mymix ->SetLineColor(kMagenta);
  mymix ->Draw("SAME");
}
