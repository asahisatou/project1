#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world455d.lib")
#else
#pragma comment(lib, "opencv_world455.lib")
#endif

int main()
{
	const char* windowName = "Image";
	

	cv::VideoCapture cap(0);
	if (!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
	{
		return -1;
	}

	while (1)
	{
		cv::Mat img;
		cap >> img;

		// 必要に応じてここに画像処理するよ
		cv::Mat gray;
		cv::Mat binary;
        cv::Mat sobel_image;
        cv::Mat laplacian_image;
        cv::Mat output_image;
		cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);    //グレースケール化
		//cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY); //２値化

        // Sobelフィルタの処理(入力画像,出力画像,出力タイプ,x方向の微分次数,y方向の微分次数,フィルタサイズ)
	    // cv::Sobel(gray, sobel_image, CV_32F, 1, 0, 3);           // x方向の微分フィルタ
	    cv::Sobel(gray, sobel_image, CV_32F, 0, 1, 3);       // y方向の微分フィルタ

        // cv::Laplacian(gray, laplacian_image, CV_32F);   //　ラプラシアンフィルタ

	    // convertScaleAbs（＝スケーリング後に絶対値を計算し，結果を8ビットに変換）
	    cv::convertScaleAbs(sobel_image, output_image, 1, 0);

	    // 閾値以上の場合にエッジ（＝白）と見なす(入力画像,出力画像,閾値,最大値,閾値タイプ)
	    // cv::threshold(output_image, output_image, 64, 255, cv::THRESH_BINARY);

		cv::imshow(windowName, output_image);//画像を表示．

		int key = cv::waitKey(1);
		if (key == 113)//qボタンが押されたとき
		{
			break;//whileループから抜ける．
		}
	}
	cv::destroyAllWindows();

	return(0);
}