
//#include "TGraphErrors.h"
 
void bw()
{
TGraphErrors *h1 = new TGraphErrors("/home/clairetemp/workspace/bw/breitWigner.dat", "\%lg \%lg"); 
h1->SetMarkerStyle(20);
h1->SetMarkerSize(1.0); 
h1->GetXaxis()->SetTitle(" Energy [MeV]");
h1->GetYaxis()->SetTitle(" Cross Section [nb]");
h1->Draw("AP");
h1->SetMinimum(0.1);

//TF1 *bwdis= new TF1("bwdis", "([0])/((x*x-[1]*[1])*(x*x-[1]*[1])+[1]*[1]*[2]*[2])", -200.,200.);

TF1 *bwdis= new TF1("bwdis", "([0]/((x-[1])*(x-[1])+[2]*[2]/4))", -200.,1000.);

bwdis->SetParLimits(0, 50000, 150000);
bwdis->SetParLimits(1, 40, 120);
bwdis->SetParLimits(2, 20, 100);

h1->Draw("AP");
bwdis->Draw("Same");
h1->Fit("bwdis");
//c1 -> Update();


}


