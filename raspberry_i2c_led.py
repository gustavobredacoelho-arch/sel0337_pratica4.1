import smbus

ENDERECO = 0x08          # mesmo endereco do Arduino
bus = smbus.SMBus(1)     # barramento I2C 1 (GPIO2 = SDA, GPIO3 = SCL)

print("Digite 1 para acender, 0 para apagar, outro valor para sair.")

while True:
    entrada = input("Comando: ").strip()
    if entrada == "1":
        bus.write_byte(ENDERECO, 1)
        print("LED aceso")
    elif entrada == "0":
        bus.write_byte(ENDERECO, 0)
        print("LED apagado")
    else:
        print("Encerrando programa.")
        break

bus.close()
