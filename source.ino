// Demo program that uses a Particle Webhook to POST data to ThingSpeak. 
// For details on the ThingSpeak Channel Feed api see: https://www.mathworks.com/help/thingspeak/update-channel-feed.html

// The Particle ThingSpeak Webhook:
// ++++++++++++++++++
//{
//    "event": "TSwriteall",
//    "url": "https://api.thingspeak.com/update?",
//    "requestType": "POST",
//    "form": {
//		"api_key": "{{k}}",
//		"field1": "{{1}}",
//		"field2": "{{2}}",
//		"field3": "{{3}}",
//		"field4": "{{4}}",
//		"field5": "{{5}}",
//		"field6": "{{6}}",
//		"field7": "{{7}}",
//		"field8": "{{8}}",
//		"lat": "{{a}}",
//		"long": "{{o}}",
//		"elevation": "{{e}}",
//		"status": "{{s}}"
//    },
//    "mydevices": true,
//	  "noDefaults": true
//}
// +++++++++++++++++

// To add the Webhook see: https://docs.particle.io/guide/tools-and-features/webhooks/

   
// For demo purposes define the ThingSpeak Channel Feed parameters
// For null values use ""
// In your own program these strings can be updated to send the desired values.

    String api_key = ""; // Replace this string with a valid ThingSpeak Write API Key.
    String field1 = "22";
    String field2 = "";  // i.e. field2 is null
    String field3 = "44";
    String field4 = "55";    
    String field5 = "";
    String field6 = "77";
    String field7 = "88";
    String field8 = "";
    String lat = "41.6483";
    String lon = "-70.4817";
    String el = "100";
    String status = "";


void setup() {

}

void loop() {
    String TSjson;
    createTSjson(TSjson);
    Particle.publish("TSwriteall",TSjson,60,PRIVATE);
    
delay(20000);
}

// Function to build the 'json' to trigger the Webhook.  To save characters the string only includes parameters that are not null.

void createTSjson(String &dest)
{
  // dest = "{ \"k\":\"" + api_key + "\", \"1\":\""+ field1 +"\", \"2\":\""+ field2 +"\",\"3\":\""+ field3 +"\",\"4\":\""+ field4 +"\",\"5\":\""+ field5 +"\",\"6\":\""+ field6 +"\",\"7\":\""+ field7 +"\",\"8\":\""+ field8 +"\",\"a\":\""+ lat +"\",\"o\":\""+ lon +"\",\"e\":\""+ el +"\", \"s\":\""+ status +"\"}";
  
    dest = "{";
    
    if(field1.length()>0){
        dest = dest + "\"1\":\""+ field1 +"\",";
    }

    if(field2.length()>0){
        dest = dest + "\"2\":\""+ field2 +"\",";
    }

    if(field3.length()>0){
        dest = dest + "\"3\":\""+ field3 +"\",";
    }

    if(field4.length()>0){
        dest = dest + "\"4\":\""+ field4 +"\",";
    }

    if(field5.length()>0){
        dest = dest + "\"5\":\""+ field5 +"\",";
    }

    if(field6.length()>0){
        dest = dest + "\"6\":\""+ field6 +"\",";
    }

    if(field7.length()>0){
        dest = dest + "\"7\":\""+ field7 +"\",";
    }

    if(field8.length()>0){
        dest = dest + "\"8\":\""+ field8 +"\",";
    }

    if(lat.length()>0){
        dest = dest + "\"a\":\""+ lat +"\",";
    }

    if(lon.length()>0){
        dest = dest + "\"o\":\""+ lon +"\",";
    }

    if(el.length()>0){
        dest = dest + "\"e\":\""+ el +"\",";
    }

    if(status.length()>0){
        dest = dest + "\"s\":\""+ status +"\",";
    }
    
    dest = dest + "\"k\":\"" + api_key + "\"}";
}
