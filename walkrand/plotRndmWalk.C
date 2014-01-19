

void plotRndmWalk()
{

	TGraphErrors *h1 = new TGraphErrors("/home/cnm08/workspace/walkrand/displ.txt", "\%lg \%lg"); 
	h1->SetMarkerStyle(20);
	h1->SetMarkerSize(0.2); 
	h1->GetXaxis()->SetTitle(" x position ");
	h1->GetYaxis()->SetTitle(" y position ");
	h1->Draw("APL");
	//h1->SetMinimum(0.1);
	

}
