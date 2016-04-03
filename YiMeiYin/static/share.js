// 微信浏览器
if (/MicroMessenger/.test(navigator.userAgent)) {
	document.write("<script type=\"text/javascript\" src=\"http://res.wx.qq.com/open/js/jweixin-1.0.0.js\"></script>");
}
$(function(){
	var blhIp = $("#blhIp").val();
	var imgUrl = 'http://vayximg1.suning.cn/printer/source/img/free_print_icon.png';
	var lineLink = 'http://'+blhIp+'/suning-web-mobile/thirdParty/printer/passthough/activity.htm?type=SHARE';
	var descContent = document.getElementById("printShareTitle").value;
	var shareTitle = '你...还在花钱打印照片？！';
	// 微信浏览器
	if (/MicroMessenger/.test(navigator.userAgent)) {
		var shareUrl =  window.location.href.indexOf("#") != -1 ? window.location.href.substr(0, window.location.href.indexOf("#")) :
			window.location.href;
		var shareAskIp = $("#shareAskIp").val();
		$.ajax({
			url: "http://"+shareAskIp+"/wgg/pservice/wxsdk/jsonp/getjsapiconfig.htm?shareUrl=" 
				+ encodeURIComponent(shareUrl) + "&appId=wx6aed9fdd44da794e",
			dataType: "jsonp",
			jsonp: "callback",
			success: function (data) {
				var config = {};
				config.appId = data.appId;
				config.timestamp = data.timestamp;
				config.nonceStr = data.nonceStr;
				config.signature = data.signature;
				config.jsApiList = ["onMenuShareTimeline", "onMenuShareAppMessage"];
				wx.error(function(res) {
					console.error("share error:" + res);
				});
				wx.config(config);
				wx.ready(function() {
					wx.onMenuShareTimeline({
						title: shareTitle, // 分享标题
						desc: descContent, // 分享描述
						link: lineLink, // 分享链接
						imgUrl: imgUrl, // 分享图标
						success: function () { 
							// 用户确认分享后执行的回调函数
							console.log("onMenuShareTimeline config ok");
						},
						cancel: function () { 
							// 用户取消分享后执行的回调函数
						}
					});
					wx.onMenuShareAppMessage({
						title: shareTitle, // 分享标题
						desc: descContent, // 分享描述
						link: lineLink, // 分享链接
						imgUrl: imgUrl, // 分享图标
						type: 'link', // 分享类型,music、video或link，不填默认为link
						dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
						success: function () { 
							// 用户确认分享后执行的回调函数
							console.log("onMenuShareAppMessage config ok");
						},
						cancel: function () { 
							// 用户取消分享后执行的回调函数
						}
					});
				});
			}
		});
	}
});