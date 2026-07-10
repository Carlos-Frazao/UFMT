import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { SwaggerModule, DocumentBuilder } from '@nestjs/swagger';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  app.enableCors();
  const config = new DocumentBuilder()
  .setTitle('Wiki Mr. Robot API')
  .setDescription('Documentação das rotas da Wiki fSociety')
  .setVersion('1.0')
  .addBearerAuth() // Isso permite colar o Token JWT no Swagger
  .build();

  const document = SwaggerModule.createDocument(app, config);
  SwaggerModule.setup('api', app, document);
  await app.listen(3000);
}

void bootstrap();
