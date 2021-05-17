import json
import meraki


API_KEY = 'aba6fd0a68d9fc6cc2449ed006b211f6ce2fc988'
network_id = 'L_676102894059001853'

dashboard = meraki.DashboardAPI(API_KEY)


response = dashboard.networks.getNetwork(
    network_id
)
print("getNetwork\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkAlertsSettings(
#     network_id
# )
# print("getNetworkAlertsSettings \n", json.dumps(response, indent=2))


#
# client_id = ''
#
# response = dashboard.networks.getNetworkClientPolicy(
#     network_id, client_id
# )
#
# print(json.dumps(response,indent=2))


# client_id = ''
#
# response = dashboard.networks.getNetworkClientSplashAuthorizationStatus(
#     network_id, client_id
# )
#
# print(json.dumps(response,indent=2))


response = dashboard.networks.getNetworkFirmwareUpgrades(
    network_id
)
print("getNetworkFirmwareUpgrades\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkFloorPlans(
#     network_id
# )
# print("getNetworkFloorPlans\n", json.dumps(response, indent=2))


# floor_plan_id = ''
#
# response = dashboard.networks.getNetworkFloorPlan(
#     network_id, floor_plan_id
# )
#
# print(json.dumps(response,indent=2))


# response = dashboard.networks.getNetworkGroupPolicies(
#     network_id
# )
# print("getNetworkGroupPolicies\n", json.dumps(response, indent=2))


#
# group_policy_id = ''
#
# response = dashboard.networks.getNetworkGroupPolicy(
#     network_id, group_policy_id
# )
#
# print(json.dumps(response,indent=2))


# response = dashboard.networks.getNetworkMerakiAuthUsers(
#     network_id
# )
# print("getNetworkMerakiAuthUsers\n", json.dumps(response, indent=2))


#
# meraki_auth_user_id = ''
#
# response = dashboard.networks.getNetworkMerakiAuthUser(
#     network_id, meraki_auth_user_id
# )
#
# print(json.dumps(response, indent=2))


#
# response = dashboard.networks.getNetworkMqttBrokers(
#     network_id
# )
#
# print(json.dumps(response, indent=2))


#
# mqtt_broker_id = ''
#
# response = dashboard.networks.getNetworkMqttBroker(
#     network_id, mqtt_broker_id
# )
#
# print(json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkNetflow(
#     network_id
# )
# print("getNetworkNetflow\n", json.dumps(response, indent=2))


response = dashboard.networks.getNetworkSettings(
    network_id
)
print("getNetworkSettings\n", json.dumps(response, indent=2))


response = dashboard.networks.getNetworkSnmp(
    network_id
)
print("getNetworkSnmp\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkSyslogServers(
#     network_id
# )
# print("getNetworkSyslogServers\n", json.dumps(response, indent=2))


response = dashboard.networks.getNetworkTrafficAnalysis(
    network_id
)
print("getNetworkTrafficAnalysis\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkTrafficShapingApplicationCategories(
#     network_id)
# print("getNetworkTrafficShapingApplicationCategories\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkTrafficShapingDscpTaggingOptions(
#     network_id)
# print("getNetworkTrafficShapingDscpTaggingOptions\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkWebhooksHttpServers(
#     network_id)
# print("getNetworkWebhooksHttpServers\n", json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkWebhooksHttpServer(
#     network_id, http_server_id)
# print(json.dumps(response, indent=2))


# response = dashboard.networks.getNetworkWebhooksWebhookTest(
#     network_id, webhook_test_id)
# print(json.dumps(response, indent=2))
